#include "CompoundStatement.hpp"

namespace parse_tree {

CompoundStatement::CompoundStatement(TerminalSymbol begin, lexer::Lexer& l) : begin(begin), statementList(l) {}

} // namespace parse_tree
