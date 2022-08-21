#ifndef PLJIT_PLJIT_ERROR_HPP
#define PLJIT_PLJIT_ERROR_HPP

//#include "../source_code_management/SourceCode.hpp"
#include "../source_code_management/SourceCodeReference.hpp"
#include <string>
namespace source_code {
struct SourceCodeReference;
}

namespace pljit {

class PLjit_Error {
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

    source_code::SourceCode* source_code = 0;
    void set_source_code(source_code::SourceCode* source_code_pointer);

    public:
    explicit PLjit_Error(source_code::SourceCodeReference source_code_reference, ErrorSource error_source, std::string error_message);

    void print();
};

} // namespace pljit

#endif //PLJIT_PLJIT_ERROR_HPP
