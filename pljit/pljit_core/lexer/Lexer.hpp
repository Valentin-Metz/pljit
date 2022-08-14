#ifndef PLJIT_LEXER_HPP
#define PLJIT_LEXER_HPP

#include "../pljit_core_utility/NonCopyable.hpp"
#include "../source_code_management/CompilationError.hpp"
#include "../source_code_management/SourceCode.hpp"
#include "../tokens/Token.hpp"
#include <expected>

class Lexer : public NonCopyable {
    const SourceCode& source_code;
    std::size_t current_parser_position = 0;
    std::size_t current_line_number = 0;
    std::size_t current_char_number = 0;

    public:
    explicit Lexer(SourceCode& sourceCode) : source_code(sourceCode) {}

    std::expected<Token, CompilationError> nextToken();
};

#endif //PLJIT_LEXER_HPP
