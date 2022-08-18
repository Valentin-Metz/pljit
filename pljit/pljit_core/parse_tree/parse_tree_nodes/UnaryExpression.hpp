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
    std::optional<std::unique_ptr<const PrimaryExpression>> primaryExpression;
    UnaryExpression(lexer::Lexer& l);
    UnaryExpression(lexer::LexerToken t, lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_UNARYEXPRESSION_HPP
