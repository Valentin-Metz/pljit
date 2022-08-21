#include "lexer/Lexer.hpp"
#include "lexer/tokens/LexerErrorToken.hpp"
#include <gtest/gtest.h>

using namespace lexer;
using namespace source_code;

extern std::string example_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(LexerTest, ValidSource) {
    SourceCode source_code{SourceCode(example_program)};
    Lexer lexer{source_code};

    // PARAM width, height, depth;\n
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);

    // VAR volume;\n
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);

    // CONST density = 2400;
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Declarator);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Literal);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);

    // BEGIN\n
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);

    // volume := width * height * depth;\n
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Assignment);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Separator);

    // RETURN density * volume\n
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Arithmetic);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Identifier);

    // END.
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Terminator);
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Error);
}

TEST(LexerTest, EmptySource) {
    SourceCode source_code{SourceCode("")};
    Lexer lexer{source_code};
    EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Error);
}

TEST(LexerTest, ValidProgramsBeginWithKeyword) {
    for (auto& string : valid_programs) {
        SourceCode source_code{string};
        Lexer lexer{source_code};
        EXPECT_EQ(lexer.nextToken()->token_type, LexerToken::Keyword);
    }
}

TEST(LexerTest, ValidProgramsEndWithTerminator) {
    for (auto& string : valid_programs) {
        SourceCode source_code{string};
        Lexer lexer{source_code};

        auto previous_token = lexer.nextToken()->token_type;
        auto current_token = lexer.nextToken()->token_type;
        while (current_token != LexerToken::Error) {
            previous_token = current_token;
            current_token = lexer.nextToken()->token_type;
        }
        EXPECT_EQ(previous_token, LexerToken::Terminator);
    }
}

TEST(LexerTest, OutOfRangeIntReturnsError) {
    SourceCode source_code{"BEGIN\n"
                           "RETURN 1 + 100000000000000000000000000000000000000\n"
                           "END."};
    Lexer lexer{source_code};

    auto token = lexer.nextToken();
    while (token->token_type != LexerToken::Error) {
        token = lexer.nextToken();
    }
    EXPECT_EQ(static_cast<LexerErrorToken&>(*token.get()).error_message, "Literal is out of range");
}
