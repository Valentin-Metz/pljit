#ifndef PLJIT_LEXERTERMINATORTOKEN_HPP
#define PLJIT_LEXERTERMINATORTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

class LexerTerminatorToken : public LexerToken {
    public:
    LexerTerminatorToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Terminator){};
};

} // namespace lexer

#endif //PLJIT_LEXERTERMINATORTOKEN_HPP
