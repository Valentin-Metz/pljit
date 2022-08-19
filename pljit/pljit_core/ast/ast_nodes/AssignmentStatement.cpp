#include "AssignmentStatement.hpp"
#include "../AstVisitor.hpp"
#include "Expression.hpp"
#include "MultiplicativeExpression.hpp"

namespace ast {

AssignmentStatement::AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Assignment), target(assignment_expression->identifier.identifier.source_code_reference.resolve(source_code)) {
    symbol_table.check_assign(target, assignment_expression->identifier.identifier.source_code_reference);
    Statement::parseAdditiveExpression(assignment_expression->additiveExpression, symbol_table, source_code, expressions, 1);
}

void AssignmentStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
void AssignmentStatement::execute(ExecutionTable& table) {
    int64_t result = 0;
    for (auto& expression : expressions) {
        if (expression->expressionType == Expression::Multiplicative) {
            result += expression->execute(table);
        } else {
            MultiplicativeExpression& m = static_cast<MultiplicativeExpression&>(*expression.get());
            if (m.multiplicativeOperator == MultiplicativeExpression::Multiply) {
                result *= expression->execute(table);
            } else {
                result /= expression->execute(table);
            }
        }
    }
    table.update(target, result);
}

} // namespace ast
