#include "ParameterDeclaration.hpp"

namespace parse_tree {

ParameterDeclaration::ParameterDeclaration(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword), declaratorList(DeclaratorList(l)) {}
void ParameterDeclaration::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
