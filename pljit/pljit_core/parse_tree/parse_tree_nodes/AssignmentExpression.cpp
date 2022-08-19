#include "AssignmentExpression.hpp"
#include "Factory.hpp"

namespace parse_tree {

AssignmentExpression::AssignmentExpression(Identifier identifier, lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator) : identifier(identifier), assignmentToken(Factory::produceAssignment(l)), additiveExpression(AdditiveExpression(l, separator)) {}
void AssignmentExpression::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
