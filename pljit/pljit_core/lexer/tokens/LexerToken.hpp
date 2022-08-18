#ifndef PLJIT_LEXERTOKEN_HPP
#define PLJIT_LEXERTOKEN_HPP

#include "../../source_code_management/SourceCodeReference.hpp"
namespace lexer {

class LexerToken {
    public:
    const source_code::SourceCodeReference source_code_reference;
    enum TokenType {
        Error,
        Keyword,
        Identifier,
        Literal,
        Separator,
        Declarator,
        Assignment,
        Arithmetic,
        Bracket,
        Terminator,
    };
    const TokenType token_type;

    protected:
    LexerToken(source_code::SourceCodeReference source_code_reference, TokenType token_type) : source_code_reference(source_code_reference), token_type(token_type) {}
    public:
    virtual ~LexerToken() = default;
};

} // namespace lexer

#endif //PLJIT_LEXERTOKEN_HPP
