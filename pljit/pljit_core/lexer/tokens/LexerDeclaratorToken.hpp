#ifndef PLJIT_LEXERDECLARATORTOKEN_HPP
#define PLJIT_LEXERDECLARATORTOKEN_HPP

#include "LexerToken.hpp"
class LexerDeclaratorToken : public LexerToken {
    public:
    LexerDeclaratorToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Declarator) {}
};

#endif //PLJIT_LEXERDECLARATORTOKEN_HPP
