#include "AssignmentStatement.hpp"

namespace ast {
AssignmentStatement::AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression) : Statement(Assignment) {
}
} // namespace ast