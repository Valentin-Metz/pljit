#ifndef PLJIT_LEXERDECLARATORTOKEN_HPP
#define PLJIT_LEXERDECLARATORTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

class LexerDeclaratorToken : public LexerToken {
    public:
    LexerDeclaratorToken(SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Declarator) {}
};

} // namespace lexer

#endif //PLJIT_LEXERDECLARATORTOKEN_HPP
