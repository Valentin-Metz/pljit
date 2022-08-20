#include "UnaryExpression.hpp"
#include "../../error_management/Error.hpp"
#include "../../lexer/tokens/LexerArithmeticToken.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"

namespace parse_tree {
UnaryExpression::UnaryExpression(lexer::Lexer& l) : UnaryExpression(l.nextToken(), l) {}
UnaryExpression::UnaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l) {
    switch (t->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::Error(t->source_code_reference, pljit::Error::Lexer, static_cast<lexer::LexerErrorToken*>(t.get())->error_message);

        case lexer::LexerToken::Arithmetic: {
            lexer::LexerArithmeticToken* a = static_cast<lexer::LexerArithmeticToken*>(t.get());
            switch (a->arithmetic_operator_type) {
                case lexer::LexerArithmeticToken::PLUS: {
                    modifier.emplace(std::make_pair(t->source_code_reference, ArithmeticSymbol::PLUS));
                    primaryExpression.emplace(std::make_unique<PrimaryExpression>(l.nextToken(), l));
                    break;
                }
                case lexer::LexerArithmeticToken::MINUS: {
                    modifier.emplace(std::make_pair(t->source_code_reference, ArithmeticSymbol::MINUS));
                    primaryExpression.emplace(std::make_unique<PrimaryExpression>(l.nextToken(), l));
                    break;
                }
                default:
                    throw pljit::Error(t->source_code_reference, pljit::Error::ParseTree, "Unexpected operator in unary-expression");
            }
            break;
        }

        default: {
            primaryExpression.emplace(std::make_unique<PrimaryExpression>(std::move(t), l));
            break;
        }
    }
}
void UnaryExpression::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
} // namespace parse_tree