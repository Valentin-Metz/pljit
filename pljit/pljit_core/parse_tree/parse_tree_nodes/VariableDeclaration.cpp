#include "VariableDeclaration.hpp"

namespace parse_tree {

VariableDeclaration::VariableDeclaration(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword), declaratorList(DeclaratorList(l)) {}
void VariableDeclaration::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
