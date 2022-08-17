#ifndef PLJIT_UNARYEXPRESSION_HPP
#define PLJIT_UNARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "ArithmeticSymbol.hpp"
#include "PrimaryExpression.hpp"
#include "TerminalSymbol.hpp"
#include <optional>
namespace parse_tree {

class UnaryExpression {
    public:
    std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> modifier;
    std::optional<const PrimaryExpression> primaryExpression;
    UnaryExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
    UnaryExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_UNARYEXPRESSION_HPP
