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
    l.nextToken();
}