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
            for (int j = 0; j < 10; ++j) {
                auto execution_table_unoptimized = ast_unoptimized.getExecutionTable();
                auto execution_table_optimized = ast_unoptimized.getExecutionTable();

                std::vector<int64_t> parameters(i, j);

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

TEST(ParseTreeTest, ExampleProgramPrint) {
    SourceCode source_code{SourceCode(example_program)};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};
    AST ast{parse_tree, source_code};

    testing::internal::CaptureStdout();
    ast.print();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "digraph AST {\n"
                                                      "AST -> SymbolTable\n"
                                                      "SymbolTable -> Parameters\n"
                                                      "SymbolTable -> Variables\n"
                                                      "SymbolTable -> Constants\n"
                                                      "Constants -> density\n"
                                                      "density -> \"2400_65536\"\n"
                                                      "\"2400_65536\" [label = \"2400\"]\n"
                                                      "Parameters -> depth\n"
                                                      "Variables -> volume\n"
                                                      "Parameters -> height\n"
                                                      "Parameters -> width\n"
                                                      "AST -> Function\n"
                                                      "Function -> Statement_0\n"
                                                      "Statement_0 -> ASSIGN_0 [color=purple]\n"
                                                      "ASSIGN_0 [label = \"ASSIGN\"]\n"
                                                      "ASSIGN_0 -> volume_65537 [color=purple]\n"
                                                      "volume_65537 [label = \"volume\"]\n"
                                                      "Statement_0 -> PLUS_65538 [color=orange]\n"
                                                      "PLUS_65538 [label = \"+\"]\n"
                                                      "PLUS_65538 -> Expression_0 [color=orange]\n"
                                                      "Expression_0 -> PLUS_65539 [color=red]\n"
                                                      "PLUS_65539 -> width_65539 [color=red]\n"
                                                      "width_65539 [label = \"width\"]\n"
                                                      "PLUS_65539 [label = \"+\"]\n"
                                                      "Expression_0 -> PLUS_65540 [color=orange]\n"
                                                      "PLUS_65540 [label = \"+\"]\n"
                                                      "PLUS_65540 -> Expression_1 [color=orange]\n"
                                                      "Expression_1 -> MULTIPLY_65541 [color=green]\n"
                                                      "MULTIPLY_65541 [label = \"*\"]\n"
                                                      "MULTIPLY_65541 -> MultiplicativeExpression_2 [color=green]\n"
                                                      "MultiplicativeExpression_2 -> PLUS_65542 [color=orange]\n"
                                                      "PLUS_65542 [label = \"+\"]\n"
                                                      "PLUS_65542 -> Expression_2 [color=orange]\n"
                                                      "Expression_2 -> PLUS_65543 [color=red]\n"
                                                      "PLUS_65543 -> height_65543 [color=red]\n"
                                                      "height_65543 [label = \"height\"]\n"
                                                      "PLUS_65543 [label = \"+\"]\n"
                                                      "Expression_1 -> PLUS_65544 [color=orange]\n"
                                                      "PLUS_65544 [label = \"+\"]\n"
                                                      "PLUS_65544 -> Expression_3 [color=orange]\n"
                                                      "Expression_3 -> MULTIPLY_65545 [color=green]\n"
                                                      "MULTIPLY_65545 [label = \"*\"]\n"
                                                      "MULTIPLY_65545 -> MultiplicativeExpression_4 [color=green]\n"
                                                      "MultiplicativeExpression_4 -> PLUS_65546 [color=orange]\n"
                                                      "PLUS_65546 [label = \"+\"]\n"
                                                      "PLUS_65546 -> Expression_4 [color=orange]\n"
                                                      "Expression_4 -> PLUS_65547 [color=red]\n"
                                                      "PLUS_65547 -> depth_65547 [color=red]\n"
                                                      "depth_65547 [label = \"depth\"]\n"
                                                      "PLUS_65547 [label = \"+\"]\n"
                                                      "Function -> Statement_1\n"
                                                      "Statement_1 -> RETURN_1 [color=pink]\n"
                                                      "RETURN_1 [label = \"RETURN\"]\n"
                                                      "Statement_1 -> PLUS_65548 [color=orange]\n"
                                                      "PLUS_65548 [label = \"+\"]\n"
                                                      "PLUS_65548 -> Expression_5 [color=orange]\n"
                                                      "Expression_5 -> PLUS_65549 [color=red]\n"
                                                      "PLUS_65549 -> density_65549 [color=red]\n"
                                                      "density_65549 [label = \"density\"]\n"
                                                      "PLUS_65549 [label = \"+\"]\n"
                                                      "Expression_5 -> PLUS_65550 [color=orange]\n"
                                                      "PLUS_65550 [label = \"+\"]\n"
                                                      "PLUS_65550 -> Expression_6 [color=orange]\n"
                                                      "Expression_6 -> MULTIPLY_65551 [color=green]\n"
                                                      "MULTIPLY_65551 [label = \"*\"]\n"
                                                      "MULTIPLY_65551 -> MultiplicativeExpression_7 [color=green]\n"
                                                      "MultiplicativeExpression_7 -> PLUS_65552 [color=orange]\n"
                                                      "PLUS_65552 [label = \"+\"]\n"
                                                      "PLUS_65552 -> Expression_7 [color=orange]\n"
                                                      "Expression_7 -> PLUS_65553 [color=red]\n"
                                                      "PLUS_65553 -> volume_65553 [color=red]\n"
                                                      "volume_65553 [label = \"volume\"]\n"
                                                      "PLUS_65553 [label = \"+\"]\n"
                                                      "}\n");
}

} // namespace ast
