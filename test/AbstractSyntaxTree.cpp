#include "ast/Ast.hpp"
#include "include/PLjit.hpp"
#include "include/PLjit_FunctionHandle.hpp"
#include <gtest/gtest.h>

using namespace source_code;
using namespace lexer;
using namespace parse_tree;
using namespace pljit;

extern std::string example_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

namespace ast {

TEST(AbstractSyntaxTreeTest, OptimizedResultEqualsUnoptimizedResult) {
    for (auto& string : valid_programs) {
        SourceCode source_code{string};
        Lexer lexer{source_code};
        ParseTree parse_tree{lexer};
        AST ast_unoptimized{parse_tree, source_code};
        AST ast_optimized{parse_tree, source_code};

        ast_optimized.optimize();

        ast_unoptimized.generateExecutionTable();
        ast_optimized.generateExecutionTable();

        for (int i = 0; i < 10; ++i) {
            auto execution_table_unoptimized = ast_unoptimized.getExecutionTable();
            auto execution_table_optimized = ast_unoptimized.getExecutionTable();

            std::vector<int64_t> parameters(i, i);

            try {
                execution_table_unoptimized.initialize(parameters);
                execution_table_optimized.initialize(parameters);

                ast_unoptimized.function->execute(execution_table_unoptimized);
                ast_optimized.function->execute(execution_table_optimized);
            } catch (pljit::PLjit_Error) { // Incorrect number of parameters
                continue;
            }

            EXPECT_EQ(execution_table_unoptimized.result, execution_table_optimized.result);
        }
    }
}

TEST(AbstractSyntaxTreeTest, InvalidProgramsReturnError) {
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

TEST(AbstractSyntaxTreeTest, DivisionByZero) {
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

} // namespace ast
