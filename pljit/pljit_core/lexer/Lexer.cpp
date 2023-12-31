#include "Lexer.hpp"
#include "tokens/LexerArithmeticToken.hpp"
#include "tokens/LexerAssignmentToken.hpp"
#include "tokens/LexerBracketToken.hpp"
#include "tokens/LexerDeclaratorToken.hpp"
#include "tokens/LexerErrorToken.hpp"
#include "tokens/LexerIdentifierToken.hpp"
#include "tokens/LexerKeywordToken.hpp"
#include "tokens/LexerLiteralToken.hpp"
#include "tokens/LexerSeparatorToken.hpp"
#include "tokens/LexerTerminatorToken.hpp"
#include <cerrno>
namespace lexer {

using namespace source_code;

std::unique_ptr<LexerToken> Lexer::nextToken() {
    const std::string_view& source_string_reference = static_cast<std::string_view>(source_code);
    while (current_parser_position <= source_string_reference.length()) {
        // Skip whitespace
        if (source_string_reference[current_parser_position] == ' ' || source_string_reference[current_parser_position] == '\t' || source_string_reference[current_parser_position] == '\n') {
            current_parser_position++;
            continue;
        }

        // Parse token

        /// Terminal expression
        if (source_string_reference[current_parser_position] == '.') {
            return std::make_unique<LexerTerminatorToken>(SourceCodeReference{current_parser_position++, 1});
        }

        /// Separator
        if (source_string_reference[current_parser_position] == ',')
            return std::make_unique<LexerSeparatorToken>(SourceCodeReference{current_parser_position++, 1}, LexerSeparatorToken::COMMA);
        if (source_string_reference[current_parser_position] == ';')
            return std::make_unique<LexerSeparatorToken>(SourceCodeReference{current_parser_position++, 1}, LexerSeparatorToken::SEMICOLON);

        /// Declarator
        if (source_string_reference[current_parser_position] == '=') {
            return std::make_unique<LexerDeclaratorToken>(SourceCodeReference{current_parser_position++, 1});
        }

        /// Assignment
        if (source_string_reference[current_parser_position] == ':') {
            if (current_parser_position + 1 >= source_string_reference.length())
                return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, 0}, "Unexpected EOF in assignment");
            if (source_string_reference[current_parser_position + 1] != '=')
                return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, 2}, "Unexpected token in assignment");
            current_parser_position += 2;
            return std::make_unique<LexerAssignmentToken>(SourceCodeReference{current_parser_position - 2, 2});
        }

        /// Arithmetic
        if (source_string_reference[current_parser_position] == '+')
            return std::make_unique<LexerArithmeticToken>(SourceCodeReference{current_parser_position++, 1}, LexerArithmeticToken::PLUS);
        if (source_string_reference[current_parser_position] == '-')
            return std::make_unique<LexerArithmeticToken>(SourceCodeReference{current_parser_position++, 1}, LexerArithmeticToken::MINUS);
        if (source_string_reference[current_parser_position] == '*')
            return std::make_unique<LexerArithmeticToken>(SourceCodeReference{current_parser_position++, 1}, LexerArithmeticToken::MULTIPLY);
        if (source_string_reference[current_parser_position] == '/')
            return std::make_unique<LexerArithmeticToken>(SourceCodeReference{current_parser_position++, 1}, LexerArithmeticToken::DIVIDE);

        /// Braces
        if (source_string_reference[current_parser_position] == '(')
            return std::make_unique<LexerBracketToken>(SourceCodeReference{current_parser_position++, 1}, LexerBracketToken::OPEN);
        if (source_string_reference[current_parser_position] == ')')
            return std::make_unique<LexerBracketToken>(SourceCodeReference{current_parser_position++, 1}, LexerBracketToken::CLOSE);

        /// Identifier or keyword
        if ((source_string_reference[current_parser_position] >= 'A' && source_string_reference[current_parser_position] <= 'Z') ||
            (source_string_reference[current_parser_position] >= 'a' && source_string_reference[current_parser_position] <= 'z')) {
            std::size_t token_start = current_parser_position++;
            while (true) {
                if (current_parser_position >= source_string_reference.length())
                    return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, 0}, "Unexpected EOF in token");
                if ((source_string_reference[current_parser_position] >= 'A' && source_string_reference[current_parser_position] <= 'Z') ||
                    (source_string_reference[current_parser_position] >= 'a' && source_string_reference[current_parser_position] <= 'z')) {
                    ++current_parser_position;
                } else {
                    /// Keyword
                    if (source_string_reference.compare(token_start, current_parser_position - token_start, "PARAM") == 0) {
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::PARAM, SourceCodeReference{token_start, current_parser_position - token_start});
                    } else if (source_string_reference.compare(token_start, current_parser_position - token_start, "VAR") == 0)
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::VAR, SourceCodeReference{token_start, current_parser_position - token_start});
                    else if (source_string_reference.compare(token_start, current_parser_position - token_start, "CONST") == 0)
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::CONST, SourceCodeReference{token_start, current_parser_position - token_start});
                    else if (source_string_reference.compare(token_start, current_parser_position - token_start, "BEGIN") == 0)
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::BEGIN, SourceCodeReference{token_start, current_parser_position - token_start});
                    else if (source_string_reference.compare(token_start, current_parser_position - token_start, "END") == 0)
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::END, SourceCodeReference{token_start, current_parser_position - token_start});
                    else if (source_string_reference.compare(token_start, current_parser_position - token_start, "RETURN") == 0)
                        return std::make_unique<LexerKeywordToken>(LexerKeywordToken::RETURN, SourceCodeReference{token_start, current_parser_position - token_start});
                    /// Identifier
                    else
                        return std::make_unique<LexerIdentifierToken>(SourceCodeReference{token_start, current_parser_position - token_start});
                }
            }
        }

        /// Literal
        if (source_string_reference[current_parser_position] >= '0' && source_string_reference[current_parser_position] <= '9') {
            char* end;
            errno = 0;

            // Parse and check errors
            const std::int64_t value{std::strtoll(&source_string_reference[current_parser_position], &end, 10)};
            if (errno == ERANGE) {
                return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, static_cast<size_t>(end - &source_string_reference[current_parser_position])}, "Literal is out of range");
            }
            if (errno) {
                return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, static_cast<size_t>(end - &source_string_reference[current_parser_position])}, "Literal parsing error: " + std::to_string(errno));
            }

            // Generate token
            std::size_t length{static_cast<size_t>(end - &source_string_reference[current_parser_position])};
            LexerLiteralToken token{LexerLiteralToken(value, SourceCodeReference{current_parser_position, length})};
            current_parser_position += length;
            return std::make_unique<LexerLiteralToken>(std::move(token));
        }

        /// Unexpected character
        return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, 1}, "Unexpected character");
    }
    return std::make_unique<LexerErrorToken>(SourceCodeReference{current_parser_position, 0}, "Unexpected EOF");
}

} // namespace lexer
