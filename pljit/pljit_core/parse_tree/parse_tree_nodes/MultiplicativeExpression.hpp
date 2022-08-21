#ifndef PLJIT_PARSETREE_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_PARSETREE_MULTIPLICATIVEEXPRESSION_HPP

#include "ArithmeticSymbol.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/Visitor/ParseTreeVisitor.hpp"
#include <memory>
#include <optional>
namespace parse_tree {

class MultiplicativeExpression {
    public:
    const std::pair<const TerminalSymbol, const ArithmeticSymbol> multiplicativeOperator;
    const UnaryExpression unaryExpression;
    MultiplicativeExpression(std::pair<TerminalSymbol, ArithmeticSymbol> multiplicativeOperator, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREE_MULTIPLICATIVEEXPRESSION_HPP
