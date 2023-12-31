#ifndef PLJIT_LEXERERRORTOKEN_HPP
#define PLJIT_LEXERERRORTOKEN_HPP

#include "LexerToken.hpp"
namespace lexer {

// This should be a https://en.cppreference.com/w/cpp/header/expected, but that requires GCC 12
class LexerErrorToken : public LexerToken {
    public:
    const std::string error_message;
    LexerErrorToken(source_code::SourceCodeReference source_code_reference, std::string error_message) : LexerToken(source_code_reference, Error), error_message(std::move(error_message)) {}
};

} // namespace lexer

#endif //PLJIT_LEXERERRORTOKEN_HPP
