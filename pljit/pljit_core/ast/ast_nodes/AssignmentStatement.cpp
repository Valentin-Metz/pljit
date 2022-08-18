#include "AssignmentStatement.hpp"

namespace ast {
AssignmentStatement::AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Assignment) {
}
} // namespace ast