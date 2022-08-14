#include "Lexer.hpp"
std::expected<Token, CompilationError> Lexer::nextToken() {
    while (current_parser_position < static_cast<std::string_view>(source_code).length()) {

    }
    return std::unexpected(CompilationError(SourceCodeReference{current_parser_position, 0, current_line_number, current_char_number}, "Unexpected EOF"));
}
