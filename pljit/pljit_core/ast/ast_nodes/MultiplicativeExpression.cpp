#include "MultiplicativeExpression.hpp"
#include "../ast_core/AstVisitor.hpp"
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
        if (expression->expressionType == Expression::Terminal) {
            result += expression->execute(table);
        } else {
            MultiplicativeExpression& m = static_cast<MultiplicativeExpression&>(*expression.get());
            if (m.multiplicativeOperator == Multiply) {
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
