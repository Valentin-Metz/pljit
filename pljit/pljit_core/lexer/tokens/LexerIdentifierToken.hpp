#ifndef PLJIT_LEXERIDENTIFIERTOKEN_HPP
#define PLJIT_LEXERIDENTIFIERTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

class LexerIdentifierToken : public LexerToken {
    public:
    LexerIdentifierToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Identifier) {}
};

} // namespace lexer

#endif //PLJIT_LEXERIDENTIFIERTOKEN_HPP
