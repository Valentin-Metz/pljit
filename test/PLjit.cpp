#include "include/PLjit.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit_FunctionHandle.hpp"
#include <gtest/gtest.h>

using namespace source_code;
using namespace lexer;
using namespace parse_tree;
using namespace ast;
using namespace pljit;

extern std::string example_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(PLjitTest, InvalidProgramsReturnError) {
    for (auto& string : invalid_programs) {
        PLjit pljit;
        auto handle = pljit.registerFunction(string);

        for (int i = 0; i < 10; ++i) {
            std::vector<int64_t> parameters(i, i);
            auto result = handle.execute(parameters);
            EXPECT_EQ(result.index(), 1);
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
    auto handle = pljit.registerFunction("BEGIN\n"
                                         "RETURN 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1\n"
                                         "END.");
    auto result = handle.execute({});

    EXPECT_EQ(result.index(), 0);
    EXPECT_EQ(std::get<0>(result), 3628800);
}
