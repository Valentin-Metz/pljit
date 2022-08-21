#include "AssignmentStatement.hpp"
#include "MultiplicativeExpression.hpp"
#include "ast/ast_core/AstVisitor.hpp"

namespace ast {

AssignmentStatement::AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Assignment), target(assignment_expression->identifier.identifier.source_code_reference.resolve(source_code)) {
    symbol_table.check_assign(target, assignment_expression->identifier.identifier.source_code_reference);
    Statement::parseAdditiveExpression(assignment_expression->additiveExpression, symbol_table, source_code, expressions, 1);
}

void AssignmentStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

void AssignmentStatement::execute(ExecutionTable& table) {
    table.update(target, Expression::evaluate_expressions(expressions, table));
}

} // namespace ast
