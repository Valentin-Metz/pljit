#include "MultiplicativeExpression.hpp"

namespace parse_tree {

MultiplicativeExpression::MultiplicativeExpression(std::pair<TerminalSymbol, ArithmeticSymbol> multiplicativeOperator, lexer::Lexer& l) : multiplicativeOperator(multiplicativeOperator), unaryExpression(l) {}
void MultiplicativeExpression::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
