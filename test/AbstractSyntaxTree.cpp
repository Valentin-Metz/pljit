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
            } catch (PLjit_Error) { // If one fails to compile, the other must, too
                EXPECT_ANY_THROW(execution_table_unoptimized.initialize(parameters));
                EXPECT_ANY_THROW(execution_table_optimized.initialize(parameters));
            }

            try {
                ast_unoptimized.function->execute(execution_table_unoptimized);
                ast_optimized.function->execute(execution_table_optimized);
            } catch (pljit::PLjit_Error) { // If one fails to execute, the other must, too
                EXPECT_ANY_THROW(ast_unoptimized.function->execute(execution_table_unoptimized));
                EXPECT_ANY_THROW(ast_optimized.function->execute(execution_table_optimized));
            }

            EXPECT_EQ(execution_table_unoptimized.result, execution_table_optimized.result);
        }
    }
}

TEST(AbstractSyntaxTreeTest, SymbolTableContainsAllSymbols) {
    SourceCode source_code{example_program};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};
    AST ast{parse_tree, source_code};

    ASSERT_EQ(ast.symbolTable.table.size(), 5);
}

TEST(AbstractSyntaxTreeTest, ExecutionTableContainsAllSymbols) {
    SourceCode source_code{example_program};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};
    AST ast{parse_tree, source_code};

    ast.generateExecutionTable();

    ExecutionTable execution_table = ast.getExecutionTable();

    ASSERT_EQ(execution_table.table.size(), 5);
}

} // namespace ast
