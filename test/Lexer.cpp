#include "../pljit/pljit_core/lexer/Lexer.hpp"
#include <gtest/gtest.h>
std::string valid_source_code = "PARAM width, height, depth;\n"
                                "VAR volume;\n"
                                "CONST density = 2400;\n\n"
                                "BEGIN\n"
                                "volume := width * height * depth;\n"
                                "RETURN density * volume\n"
                                "END.";

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

}