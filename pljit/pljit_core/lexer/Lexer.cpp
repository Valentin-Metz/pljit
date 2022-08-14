#include "Lexer.hpp"
std::expected<Token, CompilationError> Lexer::nextToken() {
    const std::string_view& source_string_reference = static_cast<std::string_view>(source_code);
    while (current_parser_position < source_string_reference.length()) {
        char current_character = source_string_reference[current_parser_position];

        // Skip whitespace
        {
            // Whitespace
            if (current_character == ' ' || current_character == '\t') {
                current_char_number++;
                current_parser_position++;
                continue;
            }
            // Newline
            if (current_character == '\n') {
                current_char_number = 0;
                current_line_number++;
                current_parser_position++;
                continue;
            }
        }

        // Parse section
        {
            switch (section_index) {
                case PRE_PARAM: {
                    if (current_character != 'P') {
                        section_index = POST_PARAM;
                        continue;
                    } else {
                        // Parse keyword "PARAM"
                        if (current_parser_position + 8 < source_string_reference.length()) return std::unexpected(CompilationError(SourceCodeReference{current_parser_position, 0, current_line_number, current_char_number}, "Unexpected EOF"));
                        if (source_string_reference[current_character + 0] != 'P' ||
                            source_string_reference[current_character + 1] != 'A' ||
                            source_string_reference[current_character + 2] != 'R' ||
                            source_string_reference[current_character + 3] != 'A' ||
                            source_string_reference[current_character + 4] != 'M') return std::unexpected(CompilationError(SourceCodeReference{current_parser_position, 5, current_line_number, current_char_number}, "Expected keyword \"PARAM\""));
                        current_parser_position += 5;
                        current_char_number += 5;
                        section_index = PARAM;
                        continue;
                    }
                }
                case PARAM: {
                    break;
                }
                case POST_PARAM: break;
                case VAR: break;
                case POST_VAR: break;
                case CONST: break;
                case POST_CONST: break;
            }
        }
    }
    return std::unexpected(CompilationError(SourceCodeReference{current_parser_position, 0, current_line_number, current_char_number}, "Unexpected EOF"));
}
