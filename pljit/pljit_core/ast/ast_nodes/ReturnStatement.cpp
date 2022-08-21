#include "ReturnStatement.hpp"
#include "../../parse_tree/parse_tree_nodes/Statement.hpp"
#include "../ast_core/AstVisitor.hpp"
#include "Expression.hpp"
#include "MultiplicativeExpression.hpp"
#include "utility.hpp"

namespace ast {
ReturnStatement::ReturnStatement(const parse_tree::AdditiveExpression* return_statement, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Return) {
    Statement::parseAdditiveExpression(*return_statement, symbol_table, source_code, expressions, 1);
}

void ReturnStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
void ReturnStatement::execute(ExecutionTable& table) {
    table.result.emplace(evaluate_expressions(expressions, table));
}

} // namespace ast
