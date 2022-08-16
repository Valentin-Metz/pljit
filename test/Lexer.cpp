#include "../pljit/pljit_core/lexer/Lexer.hpp"
#include <gtest/gtest.h>
std::string valid_source_code = "PARAM width, height, depth;\n"
                                "VAR volume;\n"
                                "CONST density = 2400;\n\n"
                                "BEGIN\n"
                                "volume := width * height * depth;\n"
                                "RETURN density * volume\n"
                                "END.";

using namespace lexer;
using namespace source_code;

TEST(LexerTest, LexerValidSource) {
    SourceCode c{SourceCode(valid_source_code)};
    Lexer l{c};

    // PARAM width, height, depth;\n
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);

    // VAR volume;\n
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);

    // CONST density = 2400;
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Declarator);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Literal);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);

    // BEGIN\n
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);

    // volume := width * height * depth;\n
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Assignment);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Separator);

    // RETURN density * volume\n
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Arithmetic);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Identifier);

    // END.
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Keyword);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Terminator);
    EXPECT_EQ(l.nextToken().token_type, LexerToken::Error);
}

TEST(LexerTest, LexerEmptySource) {
    SourceCode c{SourceCode("")};
    Lexer l{c};

    EXPECT_EQ(l.nextToken().token_type, LexerToken::Error);
}