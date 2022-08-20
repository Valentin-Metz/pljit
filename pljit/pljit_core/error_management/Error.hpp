#ifndef PLJIT_ERROR_HPP
#define PLJIT_ERROR_HPP

#include "../source_code_management/SourceCode.hpp"
#include "../source_code_management/SourceCodeReference.hpp"
#include <cstdlib>
#include <string>
#include <utility>

namespace pljit {

class Error {
    source_code::SourceCode* source_code = 0;
    void set_source_code(source_code::SourceCode* source_code_pointer);

    public:
    const source_code::SourceCodeReference source_code_reference;

    enum ErrorSource {
        Lexer,
        ParseTree,
        SymbolTable,
        AST,
        Runtime,
    };
    const ErrorSource error_source;

    const std::string error_message;

    explicit Error(source_code::SourceCodeReference source_code_reference, ErrorSource error_source, std::string error_message);

    void print();
};

} // namespace pljit

#endif //PLJIT_ERROR_HPP
