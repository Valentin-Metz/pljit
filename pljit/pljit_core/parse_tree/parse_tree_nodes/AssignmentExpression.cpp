#include "AssignmentExpression.hpp"
#include "Factory.hpp"

namespace parse_tree {

AssignmentExpression::AssignmentExpression(Identifier identifier, lexer::Lexer& l) : identifier(identifier), assignmentToken(Factory::produceAssignment(l)), additiveExpression(AdditiveExpression(l)) {}

} // namespace parse_tree
