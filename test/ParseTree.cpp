#include "parse_tree/ParseTree.hpp"
#include <gtest/gtest.h>

using namespace lexer;
using namespace source_code;
using namespace parse_tree;
using namespace pljit;

extern std::string example_program;
extern std::string factorial_calculation_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(ParseTreeTest, ExampleProgram) {
    SourceCode source_code{SourceCode(example_program)};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};

    EXPECT_EQ(parse_tree.root.parameter_declaration->declaratorList.declaratorList.size(), 3);
    EXPECT_EQ(parse_tree.root.variable_declaration->declaratorList.declaratorList.size(), 1);
    EXPECT_EQ(parse_tree.root.constant_declaration->initDeclaratorList.initDeclaratorList.size(), 1);
    EXPECT_EQ(parse_tree.root.compound_statement->statementList.statementList.size(), 2);
    EXPECT_TRUE(parse_tree.root.terminator);
}

TEST(ParseTreeTest, FactorialProgram) {
    SourceCode source_code{SourceCode(factorial_calculation_program)};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};

    EXPECT_FALSE(parse_tree.root.parameter_declaration);
    EXPECT_FALSE(parse_tree.root.variable_declaration);
    EXPECT_FALSE(parse_tree.root.constant_declaration);
    EXPECT_EQ(parse_tree.root.compound_statement->statementList.statementList.size(), 1);
    EXPECT_TRUE(parse_tree.root.terminator);
}

TEST(ParseTreeTest, ValidProgramsEndWithTerminator) {
    for (auto& string : valid_programs) {
        SourceCode source_code{string};
        Lexer lexer{source_code};
        ParseTree parse_tree{lexer};

        EXPECT_TRUE(parse_tree.root.terminator);
    }
}

TEST(ParseTreeTest, AssignmentWithoutSemicolonThrows) {
    SourceCode source_code{"VAR x;\n"
                           "BEGIN\n"
                           "x := 1337\n"
                           "RETURN x\n"
                           "END."};
    Lexer lexer{source_code};
    try {
        ParseTree parse_tree{lexer};
    } catch (PLjit_Error&) {
        SUCCEED();
        return;
    }
    FAIL();
}

TEST(ParseTreeTest, InitializingVariableThrows) {
    SourceCode source_code{"VAR x = 1337;\n"
                           "BEGIN\n"
                           "RETURN x\n"
                           "END."};
    Lexer lexer{source_code};
    try {
        ParseTree parse_tree{lexer};
    } catch (PLjit_Error&) {
        SUCCEED();
        return;
    }
    FAIL();
}

TEST(ParseTreeTest, MissingReturnStatementThrows) {
    SourceCode source_code{"BEGIN\n"
                           "END."};
    Lexer lexer{source_code};
    try {
        ParseTree parse_tree{lexer};
    } catch (PLjit_Error&) {
        SUCCEED();
        return;
    }
    FAIL();
}

TEST(ParseTreeTest, ExampleProgramPrint) {
    SourceCode source_code{SourceCode(example_program)};
    Lexer lexer{source_code};
    ParseTree parse_tree{lexer};

    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());
    parse_tree.print();
    std::cout.rdbuf(sbuf);

    EXPECT_EQ(buffer.view(), "digraph ParseTree {\n"
                             "FunctionDefinition -> ParameterDeclaration\n"
                             "ParameterDeclaration -> Keyword_PARAM_0\n"
                             "ParameterDeclaration -> DeclaratorList_6\n"
                             "DeclaratorList_6 -> Identifier_6\n"
                             "DeclaratorList_6 -> COMMA_11\n"
                             "DeclaratorList_6 -> Identifier_13\n"
                             "DeclaratorList_6 -> COMMA_19\n"
                             "DeclaratorList_6 -> Identifier_21\n"
                             "DeclaratorList_6 -> SEMICOLON_26\n"
                             "FunctionDefinition -> VariableDeclaration\n"
                             "VariableDeclaration-> Keyword_VAR_28\n"
                             "VariableDeclaration -> DeclaratorList_32\n"
                             "DeclaratorList_32 -> Identifier_32\n"
                             "DeclaratorList_32 -> SEMICOLON_38\n"
                             "FunctionDefinition -> ConstantDeclaration\n"
                             "ConstantDeclaration -> Keyword_CONST_40\n"
                             "ConstantDeclaration -> InitDeclaratorList\n"
                             "InitDeclaratorList -> InitDeclarator_46\n"
                             "InitDeclarator_46 -> Identifier_46\n"
                             "InitDeclarator_46 -> DeclarationOperator_54\n"
                             "InitDeclarator_46 -> Literal_2400_56\n"
                             "InitDeclaratorList -> SEMICOLON_60\n"
                             "FunctionDefinition -> CompoundStatement\n"
                             "CompoundStatement -> Keyword_BEGIN_63\n"
                             "CompoundStatement -> StatementList\n"
                             "StatementList -> Statement_69\n"
                             "Statement_69 -> AssignmentExpression_69\n"
                             "AssignmentExpression_69 -> Identifier_69\n"
                             "AssignmentExpression_69 -> AssignmentOperator_76\n"
                             "AssignmentExpression_69 -> AdditiveExpression_79\n"
                             "AdditiveExpression_79 -> UnaryExpression_79\n"
                             "UnaryExpression_79 -> PrimaryExpression_79\n"
                             "PrimaryExpression_79 -> Identifier_79\n"
                             "AdditiveExpression_79 -> MultiplicativeExpression_85\n"
                             "MultiplicativeExpression_85 -> ArithmeticSymbol_MULTIPLY_85\n"
                             "MultiplicativeExpression_85 -> UnaryExpression_87\n"
                             "UnaryExpression_87 -> PrimaryExpression_87\n"
                             "PrimaryExpression_87 -> Identifier_87\n"
                             "AdditiveExpression_79 -> MultiplicativeExpression_94\n"
                             "MultiplicativeExpression_94 -> ArithmeticSymbol_MULTIPLY_94\n"
                             "MultiplicativeExpression_94 -> UnaryExpression_96\n"
                             "UnaryExpression_96 -> PrimaryExpression_96\n"
                             "PrimaryExpression_96 -> Identifier_96\n"
                             "StatementList -> SEMICOLON_101\n"
                             "StatementList -> Statement_103\n"
                             "Statement_103 -> Keyword_RETURN_103\n"
                             "Statement_103 -> AdditiveExpression_110\n"
                             "AdditiveExpression_110 -> UnaryExpression_110\n"
                             "UnaryExpression_110 -> PrimaryExpression_110\n"
                             "PrimaryExpression_110 -> Identifier_110\n"
                             "AdditiveExpression_110 -> MultiplicativeExpression_118\n"
                             "MultiplicativeExpression_118 -> ArithmeticSymbol_MULTIPLY_118\n"
                             "MultiplicativeExpression_118 -> UnaryExpression_120\n"
                             "UnaryExpression_120 -> PrimaryExpression_120\n"
                             "PrimaryExpression_120 -> Identifier_120\n"
                             "StatementList -> Keyword_END_127\n"
                             "FunctionDefinition -> Terminator\n"
                             "Terminator -> DOT_130\n"
                             "}\n");
}
