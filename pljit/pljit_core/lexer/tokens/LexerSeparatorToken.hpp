#ifndef PLJIT_LEXERSEPARATORTOKEN_HPP
#define PLJIT_LEXERSEPARATORTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

class LexerSeparatorToken : public LexerToken {
    public:
    LexerSeparatorToken(source_code::SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Separator) {}
};

} // namespace lexer

#endif //PLJIT_LEXERSEPARATORTOKEN_HPP
