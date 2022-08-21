set(LEXER_SOURCES
        Lexer.hpp
        Lexer.cpp
        tokens/LexerToken.hpp
        tokens/LexerSeparatorToken.hpp
        tokens/LexerTerminatorToken.hpp
        tokens/LexerKeywordToken.hpp
        tokens/LexerIdentifierToken.hpp
        tokens/LexerLiteralToken.hpp
        tokens/LexerErrorToken.hpp
        tokens/LexerDeclaratorToken.hpp
        tokens/LexerAssignmentToken.hpp
        tokens/LexerArithmeticToken.hpp
        tokens/LexerBracketToken.hpp
        )

add_library(lexer ${LEXER_SOURCES})
target_link_libraries(lexer error_management)
