#include "MultiplicativeExpression.hpp"

namespace parse_tree {
MultiplicativeExpression::MultiplicativeExpression(std::pair<TerminalSymbol, MultiplicativeOperator> multiplicativeOperator, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) : multiplicativeOperator(multiplicativeOperator), unaryExpression(l, separator) {
}
} // namespace parse_tree