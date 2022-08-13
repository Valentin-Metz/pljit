#ifndef PLJIT_LEXER_HPP
#define PLJIT_LEXER_HPP

#include "../pljit_core_utility/NonCopyable.h"
#include "../source_code_management/SourceCode.hpp"

class Lexer : public NonCopyable {
    SourceCode& source_code;

    public:
    explicit Lexer(SourceCode& sourceCode) : source_code(sourceCode) {}
};

#endif //PLJIT_LEXER_HPP
