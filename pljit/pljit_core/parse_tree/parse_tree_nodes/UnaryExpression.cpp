#include "UnaryExpression.hpp"
#include "../../lexer/tokens/LexerArithmeticToken.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {
UnaryExpression::UnaryExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) : UnaryExpression(l.nextToken(), l, separator) {}
UnaryExpression::UnaryExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) {
    switch (t.token_type) {
        case lexer::LexerToken::Error:
            throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(t).error_message);

        case lexer::LexerToken::Arithmetic: {
            lexer::LexerArithmeticToken& a = static_cast<lexer::LexerArithmeticToken&>(t);
            switch (a.arithmetic_operator_type) {
                case lexer::LexerArithmeticToken::PLUS: {
                    modifier.emplace(std::make_pair(t.source_code_reference, ArithmeticSymbol::PLUS));
                    break;
                }
                case lexer::LexerArithmeticToken::MINUS: {
                    break;
                }
                default:
                    break;
            }
            break;
        }

        default: {
            break;
        }
    }
}
} // namespace parse_tree