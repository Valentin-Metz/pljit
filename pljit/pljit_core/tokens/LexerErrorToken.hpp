#ifndef PLJIT_LEXERERRORTOKEN_HPP
#define PLJIT_LEXERERRORTOKEN_HPP

#include "LexerToken.hpp"
class LexerErrorToken : public LexerToken {
    const std::string error_message;

    public:
    LexerErrorToken(SourceCodeReference source_code_reference, std::string error_message) : LexerToken(source_code_reference, Error), error_message(std::move(error_message)) {}
};

#endif //PLJIT_LEXERERRORTOKEN_HPP
