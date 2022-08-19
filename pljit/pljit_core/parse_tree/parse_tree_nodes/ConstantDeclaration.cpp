#include "ConstantDeclaration.hpp"

namespace parse_tree {

ConstantDeclaration::ConstantDeclaration(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword), initDeclaratorList(l) {}
void ConstantDeclaration::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
