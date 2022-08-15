#ifndef PLJIT_LEXERLITERALTOKEN_HPP
#define PLJIT_LEXERLITERALTOKEN_HPP

#include "LexerToken.hpp"
#include <cstdint>
class LexerLiteralToken : public LexerToken {
    public:
    const std::int64_t value;
    LexerLiteralToken(std::int64_t value, SourceCodeReference source_code_reference) : LexerToken(source_code_reference, Literal), value(value) {}
};

#endif //PLJIT_LEXERLITERALTOKEN_HPP
