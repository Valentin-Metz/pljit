#ifndef PLJIT_LEXER_HPP
#define PLJIT_LEXER_HPP

#include "../pljit_core_utility/NonCopyable.hpp"
#include "../source_code_management/CompilationError.hpp"
#include "../source_code_management/SourceCode.hpp"
#include "../tokens/LexerToken.hpp"
#include <expected>

class Lexer : public NonCopyable {
    const SourceCode& source_code;
    std::size_t current_parser_position = 0;

    enum sections {
        PRE_PARAM,
        PARAM,
        POST_PARAM,
        VAR,
        POST_VAR,
        CONST,
        POST_CONST,
    };
    //sections section_index = PRE_PARAM;

    public:
    explicit Lexer(SourceCode& sourceCode) : source_code(sourceCode) {}

    std::expected<LexerToken, CompilationError> nextToken();
};

#endif //PLJIT_LEXER_HPP