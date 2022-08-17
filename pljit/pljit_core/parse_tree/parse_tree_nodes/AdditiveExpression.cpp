#include "AdditiveExpression.hpp"
#include "../../lexer/tokens/LexerArithmeticToken.hpp"
#include "../../lexer/tokens/LexerBracketToken.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {

AdditiveExpression::AdditiveExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) : AdditiveExpression(l.nextToken(), l, separator) {}
AdditiveExpression::AdditiveExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) : unaryExpression(t, l, separator) {
    while (!separator && !additiveExpression) {
        lexer::LexerToken t{l.nextToken()};
        switch (t.token_type) {
            case lexer::LexerToken::Error:
                throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(t).error_message);

            /// additive-expression -> unary-expression -> primary-expression
            case lexer::LexerToken::Identifier:
            case lexer::LexerToken::Literal: {
                std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> o;
                additiveExpression.emplace(std::make_pair(o, std::make_unique<AdditiveExpression>(AdditiveExpression(t, l, separator))));
                break;
            }

            /// (+ | -) additive-expression -> unary-expression -> primary-expression
            /// (* | /) multiplicative-expression
            case lexer::LexerToken::Arithmetic: {
                lexer::LexerArithmeticToken& a = static_cast<lexer::LexerArithmeticToken&>(t);
                switch (a.arithmetic_operator_type) {
                    case lexer::LexerArithmeticToken::PLUS: {
                        additiveExpression.emplace(std::make_pair(std::make_pair(TerminalSymbol(a.source_code_reference), ArithmeticSymbol::PLUS), std::make_unique<const AdditiveExpression>(l, separator)));
                        break;
                    }
                    case lexer::LexerArithmeticToken::MINUS: {
                        additiveExpression.emplace(std::make_pair(std::make_pair(TerminalSymbol(a.source_code_reference), ArithmeticSymbol::MINUS), std::make_unique<const AdditiveExpression>(l, separator)));
                        break;
                    }
                    case lexer::LexerArithmeticToken::MULTIPLY: {
                        multiplicativeExpression.push_back(std::make_unique<MultiplicativeExpression>(std::make_pair(TerminalSymbol(a.source_code_reference), ArithmeticSymbol::MULTIPLY), l, separator));
                        break;
                    }
                    case lexer::LexerArithmeticToken::DIVIDE: {
                        multiplicativeExpression.push_back(std::make_unique<MultiplicativeExpression>(std::make_pair(TerminalSymbol(a.source_code_reference), ArithmeticSymbol::DIVIDE), l, separator));
                        break;
                    }
                }
                break;
            }

            /// Expression is over; transmit separator
            case lexer::LexerToken::Bracket: {
                lexer::LexerBracketToken& b = static_cast<lexer::LexerBracketToken&>(t);
                /// additive-expression -> unary-expression -> primary-expression
                if (b.bracket_type == lexer::LexerBracketToken::OPEN) {
                    std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> o;
                    additiveExpression.emplace(std::make_pair(o, std::make_unique<AdditiveExpression>(t, l, separator)));
                    break;
                }
                [[fallthrough]];
            }
            case lexer::LexerToken::Keyword:
            case lexer::LexerToken::Separator: {
                separator.emplace(t);
                break;
            }
            default:
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Unexpected token in additive-expression");
        }
    }
}

} // namespace parse_tree
