#include "pljit_core/lexer/Lexer.hpp"
#include <gtest/gtest.h>

using namespace lexer;
using namespace source_code;

extern std::string example_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(ParseTreeTest, ValidSource) {
    SourceCode c{SourceCode(example_program)};
    Lexer l{c};

    // PARAM width, height, depth;\n
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);

    // VAR volume;\n
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);

    // CONST density = 2400;
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Declarator);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Literal);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);

    // BEGIN\n
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);

    // volume := width * height * depth;\n
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Assignment);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Separator);

    // RETURN density * volume\n
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Identifier);

    // END.
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Terminator);
    EXPECT_EQ(l.nextToken()->token_type, LexerToken::Error);
}