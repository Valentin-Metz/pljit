#ifndef PLJIT_COMPILATIONERROR_HPP
#define PLJIT_COMPILATIONERROR_HPP

#include <cstdlib>
#include <string>
#include <utility>
class CompilationError {
    std::size_t line_number;
    std::size_t character_number;
    std::string error_message;

    explicit CompilationError(std::size_t line_number, std::size_t character_number, std::string error_message)
        : line_number(line_number), character_number(character_number), error_message(std::move(error_message)) {}
};

#endif //PLJIT_COMPILATIONERROR_HPP
