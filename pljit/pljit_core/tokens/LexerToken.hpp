#ifndef PLJIT_LEXERTOKEN_HPP
#define PLJIT_LEXERTOKEN_HPP

#include "../source_code_management/SourceCodeReference.hpp"
class LexerToken {
    const SourceCodeReference source_code_reference;

    public:
    enum TokenType {
        Error,
        Keyword,
        Identifier,
        Literal,
        Separator,
        Declarator,
        Assignment,
        Arithmetic,
        Terminator,
    };
    const TokenType token_type;

    protected:
    LexerToken(SourceCodeReference source_code_reference, TokenType token_type) : source_code_reference(source_code_reference), token_type(token_type) {}
};

#endif //PLJIT_LEXERTOKEN_HPP
