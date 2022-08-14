#ifndef PLJIT_LEXERTOKEN_HPP
#define PLJIT_LEXERTOKEN_HPP

#include "../source_code_management/SourceCodeReference.hpp"
class LexerToken {
    const SourceCodeReference source_code_reference;

    public:
    LexerToken(SourceCodeReference source_code_reference) : source_code_reference(source_code_reference) {}
};

#endif //PLJIT_LEXERTOKEN_HPP
