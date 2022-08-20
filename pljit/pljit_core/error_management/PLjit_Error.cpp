#include "PLjit_Error.hpp"
#include <iostream>

namespace pljit {

PLjit_Error::PLjit_Error(source_code::SourceCodeReference source_code_reference, PLjit_Error::ErrorSource error_source, std::string error_message)
    : source_code_reference(source_code_reference), error_source(error_source), error_message(std::move(error_message)) {}

void PLjit_Error::set_source_code(source_code::SourceCode* source_code_pointer) { source_code = source_code_pointer; }

void PLjit_Error::print() {
    if (error_source == Runtime) {
        std::cout << "Runtime error: " << error_message << std::endl;
        return;
    }

    std::size_t line_number = 0;
    std::size_t last_linebreak = 0;

    for (std::size_t i = 0; i < source_code_reference.byte_index; ++i) {
        if (source_code->source_code[i] == '\n') {
            last_linebreak = i;
            line_number++;
        }
    }

    std::size_t character_position = source_code_reference.byte_index - last_linebreak - 1;

    // Human line numbers start at 1
    std::cout << (line_number + 1) << ":" << character_position << ": ";

    switch (error_source) {
        case Lexer: {
            std::cout << "Lexer error:";
            break;
        }
        case ParseTree: {
            std::cout << "ParseTree error:";
            break;
        }
        case SymbolTable: {
            std::cout << "SymbolTable error:";
            break;
        }
        case AST: {
            std::cout << "AST error:";
            break;
        }
        default:
            break;
    }
    std::cout << "\n";

    // Print line where error occurred
    for (std::size_t i = last_linebreak + 1; i < source_code->source_code.length() && source_code->source_code[i] != '\n'; ++i) {
        std::cout << source_code->source_code[i];
    }
    std::cout << "\n";

    // Underline erroneous position
    for (std::size_t i = 0; i < character_position; ++i) {
        std::cout << " ";
    }
    for (std::size_t i = 0; i < source_code_reference.reference_length; ++i) {
        std::cout << "^";
    }
    std::cout << "\n";

    std::cout << error_message << std::endl;
}

} // namespace pljit
