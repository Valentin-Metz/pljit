#ifndef PLJIT_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_MULTIPLICATIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "ArithmeticSymbol.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include <memory>
#include <optional>
namespace parse_tree {

class MultiplicativeExpression {
    public:
    const std::pair<const TerminalSymbol, const ArithmeticSymbol> multiplicativeOperator;
    const UnaryExpression unaryExpression;
    MultiplicativeExpression(std::pair<TerminalSymbol, ArithmeticSymbol> multiplicativeOperator, lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_MULTIPLICATIVEEXPRESSION_HPP
