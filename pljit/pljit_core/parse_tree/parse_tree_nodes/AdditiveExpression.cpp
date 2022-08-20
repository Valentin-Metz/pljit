#include "AdditiveExpression.hpp"
#include "../../error_management/Error.hpp"
#include "../../lexer/tokens/LexerArithmeticToken.hpp"
#include "../../lexer/tokens/LexerBracketToken.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include <memory>

namespace parse_tree {

AdditiveExpression::AdditiveExpression(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator) : AdditiveExpression(l.nextToken(), l, separator) {}
AdditiveExpression::AdditiveExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator) : unaryExpression(std::move(t), l) {
    while (!separator && !additiveExpression) {
        std::unique_ptr<lexer::LexerToken> token{l.nextToken()};
        switch (token->token_type) {
            case lexer::LexerToken::Error:
                throw pljit::Error(token->source_code_reference, pljit::Error::Lexer, static_cast<lexer::LexerErrorToken*>(token.get())->error_message);

            /// additive-expression -> unary-expression -> primary-expression
            case lexer::LexerToken::Identifier:
            case lexer::LexerToken::Literal: {
                std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> o;
                additiveExpression.emplace(std::make_pair(o, std::make_unique<AdditiveExpression>(AdditiveExpression(std::move(token), l, separator))));
                break;
            }

            /// (+ | -) additive-expression -> unary-expression -> primary-expression
            /// (* | /) multiplicative-expression
            case lexer::LexerToken::Arithmetic: {
                lexer::LexerArithmeticToken* a = static_cast<lexer::LexerArithmeticToken*>(token.get());
                switch (a->arithmetic_operator_type) {
                    case lexer::LexerArithmeticToken::PLUS: {
                        additiveExpression.emplace(std::make_pair(std::make_pair(TerminalSymbol(a->source_code_reference), ArithmeticSymbol::PLUS), std::make_unique<const AdditiveExpression>(l, separator)));
                        break;
                    }
                    case lexer::LexerArithmeticToken::MINUS: {
                        additiveExpression.emplace(std::make_pair(std::make_pair(TerminalSymbol(a->source_code_reference), ArithmeticSymbol::MINUS), std::make_unique<const AdditiveExpression>(l, separator)));
                        break;
                    }
                    case lexer::LexerArithmeticToken::MULTIPLY: {
                        multiplicativeExpression.push_back(std::make_unique<MultiplicativeExpression>(std::make_pair(TerminalSymbol(a->source_code_reference), ArithmeticSymbol::MULTIPLY), l));
                        break;
                    }
                    case lexer::LexerArithmeticToken::DIVIDE: {
                        multiplicativeExpression.push_back(std::make_unique<MultiplicativeExpression>(std::make_pair(TerminalSymbol(a->source_code_reference), ArithmeticSymbol::DIVIDE), l));
                        break;
                    }
                }
                break;
            }

            /// Expression is over; transmit separator
            case lexer::LexerToken::Bracket: {
                lexer::LexerBracketToken* b = static_cast<lexer::LexerBracketToken*>(token.get());
                /// additive-expression -> unary-expression -> primary-expression
                if (b->bracket_type == lexer::LexerBracketToken::OPEN) {
                    std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> o;
                    additiveExpression.emplace(std::make_pair(o, std::make_unique<AdditiveExpression>(std::move(token), l, separator)));
                    break;
                }
                [[fallthrough]];
            }
            case lexer::LexerToken::Keyword:
            case lexer::LexerToken::Separator: {
                separator.emplace(std::move(token));
                break;
            }
            default:
                throw pljit::Error(token->source_code_reference, pljit::Error::ParseTree, "Unexpected token in additive-expression");
        }
    }
}
void AdditiveExpression::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
