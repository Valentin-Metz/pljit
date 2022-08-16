#ifndef PLJIT_LEXERASSIGNMENTTOKEN_HPP
#define PLJIT_LEXERASSIGNMENTTOKEN_HPP

#include "LexerToken.hpp"
class LexerAssignmentToken : public LexerToken {
    public:
    LexerAssignmentToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Assignment) {}
};

#endif //PLJIT_LEXERASSIGNMENTTOKEN_HPP
