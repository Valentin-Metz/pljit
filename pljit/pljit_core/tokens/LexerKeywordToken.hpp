#ifndef PLJIT_LEXERKEYWORDTOKEN_HPP
#define PLJIT_LEXERKEYWORDTOKEN_HPP

#include "LexerToken.hpp"
class LexerKeywordToken : public LexerToken {
    public:
    enum KeywordType {
        PARAM,
        VAR,
        CONST,
        BEGIN,
        END,
        RETURN,
    };
    const KeywordType keyword_type;
    LexerKeywordToken(KeywordType keyword_type, SourceCodeReference source_code_reference) : LexerToken(source_code_reference), keyword_type(keyword_type) {}
};

#endif //PLJIT_LEXERKEYWORDTOKEN_HPP
