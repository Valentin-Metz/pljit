#include "utility.hpp"
#include "MultiplicativeExpression.hpp"
namespace ast {

/// Evaluates a list of expressions and returns their result
std::int64_t evaluate_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ExecutionTable& table) {
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
