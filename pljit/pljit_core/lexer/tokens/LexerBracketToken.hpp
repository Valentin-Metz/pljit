#ifndef PLJIT_LEXERBRACKETTOKEN_HPP
#define PLJIT_LEXERBRACKETTOKEN_HPP

#include "LexerToken.hpp"
class LexerBracketToken : public LexerToken {
    public:
    enum BracketType {
        OPEN,
        CLOSE,
    };
    const BracketType bracket_type;
    LexerBracketToken(SourceCodeReference source_code_reference, BracketType bracket_type) : LexerToken(source_code_reference, Bracket), bracket_type(bracket_type) {}
};

#endif //PLJIT_LEXERBRACKETTOKEN_HPP
