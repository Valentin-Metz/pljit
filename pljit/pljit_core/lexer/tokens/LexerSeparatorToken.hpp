#ifndef PLJIT_LEXERSEPARATORTOKEN_HPP
#define PLJIT_LEXERSEPARATORTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

class LexerSeparatorToken : public LexerToken {
    public:
    enum SeparatorType {
        COMMA,
        SEMICOLON,
    };
    const SeparatorType separator_type;
    LexerSeparatorToken(source_code::SourceCodeReference source_code_reference, SeparatorType separator_type) : LexerToken(source_code_reference, Separator), separator_type(separator_type) {}
};

} // namespace lexer

#endif //PLJIT_LEXERSEPARATORTOKEN_HPP
