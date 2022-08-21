#ifndef PLJIT_PLJIT_ERROR_HPP
#define PLJIT_PLJIT_ERROR_HPP

#include <string>

// Lightweight struct which don't want to allocate on the heap
#include "source_code_management/SourceCodeReference.hpp"

namespace pljit {

/// This class is used to indicate an error that occurred at any stage of our program - from compilation to execution
class PLjit_Error {
    friend class PLjit_FunctionHandle;

    public:
    enum ErrorSource {
        Lexer,
        ParseTree,
        SymbolTable,
        AST,
        Runtime,
    };

    private:
    const source_code::SourceCodeReference source_code_reference;

    const ErrorSource error_source;
    const std::string error_message;

    // Not set during construction, as the error-creators usually operate source-code independent
    source_code::SourceCode* source_code = 0;
    void set_source_code(source_code::SourceCode* source_code_pointer);

    public:
    PLjit_Error(source_code::SourceCodeReference source_code_reference, ErrorSource error_source, std::string error_message);
    ~PLjit_Error();

    /// The error content can be printed to std::out, displaying the source of the error in a user-friendly way
    void print();
};

} // namespace pljit

#endif //PLJIT_PLJIT_ERROR_HPP
