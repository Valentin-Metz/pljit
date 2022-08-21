#include "include/PLjit.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit_FunctionHandle.hpp"
#include <thread>
#include <gtest/gtest.h>

using namespace source_code;
using namespace lexer;
using namespace parse_tree;
using namespace ast;
using namespace pljit;

extern std::string example_program;
extern std::string factorial_calculation_program;
extern std::string leet_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(PLjitTest, ValidProgramsSucceed) {
    for (auto& string : valid_programs) {
        PLjit pljit;
        auto handle = pljit.registerFunction(string);

        bool succeeded_once = false;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::vector<int64_t> parameters(i, j);
                auto result = handle.execute(parameters);
                if (result.index() == 0) {
                    succeeded_once = true;
                }
            }
        }
        EXPECT_TRUE(succeeded_once);
    }
}

TEST(PLjitTest, InvalidProgramsReturnError) {
    for (auto& string : invalid_programs) {
        PLjit pljit;
        auto handle = pljit.registerFunction(string);

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::vector<int64_t> parameters(i, j);
                auto result = handle.execute(parameters);
                EXPECT_EQ(result.index(), 1);
            }
        }
    }
}

TEST(PLjitTest, DivisionByZero) {
    PLjit pljit;
    auto handle = pljit.registerFunction("BEGIN\n"
                                         "RETURN 1 / 0\n"
                                         "END.");
    auto result = handle.execute({});

    EXPECT_EQ(result.index(), 1);

    testing::internal::CaptureStdout();
    std::get<1>(result).print();

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Runtime error: Division by zero\n");
}

TEST(PLjitTest, FactorialCalculation) {
    PLjit pljit;
    auto handle = pljit.registerFunction(factorial_calculation_program);
    auto result = handle.execute({});

    EXPECT_EQ(result.index(), 0);
    EXPECT_EQ(std::get<0>(result), 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1);
}

TEST(PLjitTest, ParamterVarConstLiteral) {
    PLjit pljit;
    auto handle = pljit.registerFunction(leet_program);
    auto result = handle.execute({1337, 3});

    EXPECT_EQ(result.index(), 0);
    EXPECT_EQ(std::get<0>(result), 1337);
}

TEST(PLjitTest, MultithreadedCalculation) {
    PLjit pljit;
    auto handle = pljit.registerFunction(leet_program);

    std::atomic<int64_t> result_sum = 0;

    auto original_handle = [&result_sum, &handle]() {
        int64_t result = std::get<0>(handle.execute({1337, 3}));
        EXPECT_EQ(result, 1337);
        result_sum += result;
    };
    auto copy_handle = [&result_sum](PLjit_FunctionHandle handle) {
        int64_t result = std::get<0>(handle.execute({1337, 3}));
        EXPECT_EQ(result, 1337);
        result_sum += result;
    };

    std::vector<std::unique_ptr<std::thread>> threads;
    for (int i = 0; i < 1337; ++i) {
        threads.push_back(std::make_unique<std::thread>(original_handle));
        threads.push_back(std::make_unique<std::thread>(copy_handle, handle));
    }
    for (auto& thread : threads) {
        thread->join();
    }

    EXPECT_EQ(result_sum, 1337 * 1337 * 2);
}
