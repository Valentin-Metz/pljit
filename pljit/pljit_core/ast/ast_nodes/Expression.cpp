#include "Expression.hpp"
#include "MultiplicativeExpression.hpp"
#include "ast/ast_core/ExecutionTable.hpp"

namespace ast {

Expression::~Expression() = default;

Expression::Expression(const ExpressionType expression_type) : expressionType(expression_type) {}
std::int64_t Expression::evaluate_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ExecutionTable& table) {
    int64_t result = 0;
    for (auto& expression : expressions) {
        if (expression->expressionType == Expression::Terminal) {
            result += expression->execute(table);
        } else {
            MultiplicativeExpression& m = static_cast<MultiplicativeExpression&>(*expression.get());
            if (m.multiplicativeOperator == MultiplicativeExpression::Multiply) {
                result *= expression->execute(table);
            } else {
                int64_t divisor = expression->execute(table);
                if (divisor == 0) throw pljit::PLjit_Error({0, 0}, pljit::PLjit_Error::Runtime, "Division by zero");
                result /= divisor;
            }
        }
    }
    return result;
}

} // namespace ast
