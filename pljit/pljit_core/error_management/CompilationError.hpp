#ifndef PLJIT_COMPILATIONERROR_HPP
#define PLJIT_COMPILATIONERROR_HPP

#include "../source_code_management/SourceCode.hpp"
#include "../source_code_management/SourceCodeReference.hpp"
#include "Error.hpp"
#include <cstdlib>
#include <string>
#include <utility>

class CompilationError : public pljit::Error {
    public:
    const source_code::SourceCodeReference source_code_reference;
    enum ErrorSource {
        Lexer,
        ParseTree,
        SymbolTable,
        AST,
    };
    const ErrorSource error_source;
    const std::string error_message;

    explicit CompilationError(source_code::SourceCodeReference source_code_reference, ErrorSource error_source, std::string error_message);

    void print(source_code::SourceCode& source_code);
};

#endif //PLJIT_COMPILATIONERROR_HPP
