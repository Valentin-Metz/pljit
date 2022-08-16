#ifndef PLJIT_LEXERASSIGNMENTTOKEN_HPP
#define PLJIT_LEXERASSIGNMENTTOKEN_HPP

#include "LexerToken.hpp"

namespace lexer {
class LexerAssignmentToken : public LexerToken {
    public:
    LexerAssignmentToken(source_code::SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Assignment) {}
};

} // namespace lexer

#endif //PLJIT_LEXERASSIGNMENTTOKEN_HPP
