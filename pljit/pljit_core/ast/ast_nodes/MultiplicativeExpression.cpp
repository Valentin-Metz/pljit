#include "MultiplicativeExpression.hpp"
#include "../AstVisitor.hpp"
#include "Statement.hpp"

namespace ast {
MultiplicativeExpression::MultiplicativeExpression(MultiplicativeOperator multiplicative_operator, const parse_tree::UnaryExpression& unary_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Expression(Multiplicative), multiplicativeOperator(multiplicative_operator) {
    Statement::parseUnaryExpression(unary_expression, symbol_table, source_code, expressions, 1);
}

void MultiplicativeExpression::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
int64_t MultiplicativeExpression::execute(ExecutionTable& table) {
    int64_t result = 0;
    for (auto& expression : expressions) {
        if (expression->expressionType == Expression::Multiplicative) {
            result += expression->execute(table);
        } else {
            MultiplicativeExpression& m = static_cast<MultiplicativeExpression&>(*expression.get());
            if (m.multiplicativeOperator == Multiply) {
                result *= expression->execute(table);
            } else {
                result /= expression->execute(table);
            }
        }
    }
    return result;
}

} // namespace ast
