#ifndef PLJIT_LEXERTERMINATORTOKEN_HPP
#define PLJIT_LEXERTERMINATORTOKEN_HPP

#include "LexerToken.hpp"
class LexerTerminatorToken : public LexerToken {
    public:
    LexerTerminatorToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference){};
};

#endif //PLJIT_LEXERTERMINATORTOKEN_HPP
