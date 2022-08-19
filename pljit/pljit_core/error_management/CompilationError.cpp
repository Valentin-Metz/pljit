#include "CompilationError.hpp"
#include <iostream>
void CompilationError::print(source_code::SourceCode& source_code) {
    std::size_t line_number = 0;
    std::size_t character_position = 0;

    for (std::size_t i = 0; i < source_code_reference.byte_index; ++i) {
        if (source_code.source_code[i] == '\n') line_number++;
    }
    for (std::size_t i = 0; i < source_code_reference.byte_index; ++i) {
        if (source_code.source_code[source_code_reference.byte_index - i] != '\n')
            character_position++;
        else
            break;
    }

    std::cout << line_number << ":" << character_position << ": ";

    switch (error_source) {
        case Lexer: {
            std::cout << "Lexer error: " << error_message;
            break;
        }
        case ParseTree: {
            std::cout << "ParseTree error: " << error_message;
            break;
        }
        case SymbolTable: {
            std::cout << "SymbolTable error: " << error_message;
            break;
        }
        case AST: {
            std::cout << "AST error: " << error_message;
            break;
        }
    }

    std::cout << std::endl;
}
