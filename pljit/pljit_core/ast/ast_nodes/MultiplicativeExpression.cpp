#include "MultiplicativeExpression.hpp"
#include "Statement.hpp"
#include "ast/ast_core/AstVisitor.hpp"
#include "utility.hpp"

namespace ast {

MultiplicativeExpression::MultiplicativeExpression(MultiplicativeOperator multiplicative_operator, const parse_tree::UnaryExpression& unary_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Expression(Multiplicative), multiplicativeOperator(multiplicative_operator) {
    Statement::parseUnaryExpression(unary_expression, symbol_table, source_code, expressions, 1);
}

void MultiplicativeExpression::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

int64_t MultiplicativeExpression::execute(ExecutionTable& table) {
    return evaluate_expressions(expressions, table);
}

} // namespace ast
