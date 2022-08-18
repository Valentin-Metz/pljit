#include "MultiplicativeExpression.hpp"

namespace parse_tree {

MultiplicativeExpression::MultiplicativeExpression(std::pair<TerminalSymbol, ArithmeticSymbol> multiplicativeOperator, lexer::Lexer& l) : multiplicativeOperator(multiplicativeOperator), unaryExpression(l) {}

} // namespace parse_tree
