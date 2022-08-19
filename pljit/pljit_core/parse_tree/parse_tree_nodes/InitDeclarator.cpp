#include "InitDeclarator.hpp"
#include "Factory.hpp"

namespace parse_tree {

InitDeclarator::InitDeclarator(lexer::Lexer& l) : identifier(l), assignment_symbol(Factory::produceDeclarator(l)), literal(l) {}
void InitDeclarator::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
