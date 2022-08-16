#ifndef PLJIT_LEXER_HPP
#define PLJIT_LEXER_HPP

#include "../pljit_core_utility/NonCopyable.hpp"
#include "../source_code_management/SourceCode.hpp"
#include "./tokens/LexerToken.hpp"
namespace lexer {

class Lexer : public NonCopyable {
    const SourceCode& source_code;
    std::size_t current_parser_position = 0;

    public:
    explicit Lexer(SourceCode& sourceCode) : source_code(sourceCode) {}

    LexerToken nextToken();
};

} // namespace lexer

#endif //PLJIT_LEXER_HPP
