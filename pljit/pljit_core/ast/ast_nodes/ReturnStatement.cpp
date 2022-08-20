#include "ReturnStatement.hpp"
#include "../../parse_tree/parse_tree_nodes/Statement.hpp"
#include "../ast_core/AstVisitor.hpp"
#include "Expression.hpp"
#include "MultiplicativeExpression.hpp"

namespace ast {
ReturnStatement::ReturnStatement(const parse_tree::AdditiveExpression* return_statement, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Return) {
    Statement::parseAdditiveExpression(*return_statement, symbol_table, source_code, expressions, 1);
}

void ReturnStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
void ReturnStatement::execute(ExecutionTable& table) {
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
                if (divisor == 0) throw pljit::Error({0, 0}, pljit::Error::Runtime, "Division by zero");
                result /= divisor;
            }
        }
    }
    table.result.emplace(result);
}

} // namespace ast
