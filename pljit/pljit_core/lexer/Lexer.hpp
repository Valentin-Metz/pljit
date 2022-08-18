#ifndef PLJIT_LEXER_HPP
#define PLJIT_LEXER_HPP

#include "../pljit_core_utility/NonCopyable.hpp"
#include "../source_code_management/SourceCode.hpp"
#include "./tokens/LexerToken.hpp"
#include <memory>
namespace lexer {

class Lexer : public NonCopyable {
    const source_code::SourceCode& source_code;
    std::size_t current_parser_position = 0;

    public:
    explicit Lexer(source_code::SourceCode& sourceCode) : source_code(sourceCode) {}

    std::unique_ptr<LexerToken> nextToken();
};

} // namespace lexer

#endif //PLJIT_LEXER_HPP
