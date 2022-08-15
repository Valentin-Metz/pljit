#ifndef PLJIT_LEXERSEPARATORTOKEN_HPP
#define PLJIT_LEXERSEPARATORTOKEN_HPP

#include "LexerToken.hpp"
class LexerSeparatorToken : public LexerToken {
    public:
    LexerSeparatorToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Separator) {}
};

#endif //PLJIT_LEXERSEPARATORTOKEN_HPP
