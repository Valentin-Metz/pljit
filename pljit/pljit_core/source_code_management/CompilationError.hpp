#ifndef PLJIT_COMPILATIONERROR_HPP
#define PLJIT_COMPILATIONERROR_HPP

#include "SourceCodeReference.hpp"
#include <cstdlib>
#include <string>
#include <utility>
class CompilationError {
    const SourceCodeReference source_code_reference;
    const std::string error_message;

    public:
    explicit CompilationError(SourceCodeReference source_code_reference, std::string error_message)
        : source_code_reference(source_code_reference), error_message(std::move(error_message)) {}
};

#endif //PLJIT_COMPILATIONERROR_HPP
