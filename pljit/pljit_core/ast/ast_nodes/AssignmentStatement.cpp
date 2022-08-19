#include "AssignmentStatement.hpp"
#include "../AstVisitor.hpp"

namespace ast {
AssignmentStatement::AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Assignment) {
    symbol_table.check_assign(assignment_expression->identifier.identifier.source_code_reference.resolve(source_code), assignment_expression->identifier.identifier.source_code_reference);
    Statement::parseAdditiveExpression(assignment_expression->additiveExpression, symbol_table, source_code, expressions, 1);
}

void AssignmentStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

} // namespace ast
