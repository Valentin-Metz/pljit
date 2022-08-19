#include "CompoundStatement.hpp"
#include "Statement.hpp"

namespace parse_tree {

CompoundStatement::CompoundStatement(TerminalSymbol begin, lexer::Lexer& l) : begin(begin), statementList(l) {}
void CompoundStatement::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
