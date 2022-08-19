#include "Statement.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "Expression.hpp"
#include "MultiplicativeExpression.hpp"
#include "TerminalExpression.hpp"

namespace ast {
Statement::~Statement() {
}
Statement::Statement(Statement::StatementType statement_type) : statementType(statement_type) {
}

void Statement::parseUnaryExpression(const parse_tree::UnaryExpression& unary_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign) {
    if (unary_expression.modifier && unary_expression.modifier.value().second == ArithmeticSymbol::MINUS) sign *= -1;

    if (unary_expression.primaryExpression.value()->identifier) {
        symbol_table.check_assign(unary_expression.primaryExpression.value()->identifier.value().identifier.source_code_reference.resolve(source_code),
                                  unary_expression.primaryExpression.value()->identifier.value().identifier.source_code_reference);
        expressions.push_back(std::make_unique<TerminalExpression>(std::make_pair(sign, unary_expression.primaryExpression.value()->identifier.value().identifier.source_code_reference.resolve(source_code))));
    }
    if (unary_expression.primaryExpression.value()->literal) {
        expressions.push_back(std::make_unique<TerminalExpression>(unary_expression.primaryExpression.value()->literal.value().literal.second * sign));
    }
    if (unary_expression.primaryExpression.value()->additiveExpression) {
        Statement::parseAdditiveExpression(*unary_expression.primaryExpression.value()->additiveExpression.value(), symbol_table, source_code, expressions, sign);
    }
}

static void parseMultiplicativeExpression(const parse_tree::MultiplicativeExpression& multiplicative_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions) {
    if (multiplicative_expression.multiplicativeOperator.second == ArithmeticSymbol::MULTIPLY) {
        expressions.push_back(std::make_unique<MultiplicativeExpression>(MultiplicativeExpression::Multiply, multiplicative_expression.unaryExpression, symbol_table, source_code));
    } else {
        expressions.push_back(std::make_unique<MultiplicativeExpression>(MultiplicativeExpression::Divide, multiplicative_expression.unaryExpression, symbol_table, source_code));
    }
}

void Statement::parseAdditiveExpression(const parse_tree::AdditiveExpression& additive_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign) {
    parseUnaryExpression(additive_expression.unaryExpression, symbol_table, source_code, expressions, sign);
    for (auto& multiplicative_expression : additive_expression.multiplicativeExpression) {
        parseMultiplicativeExpression(*multiplicative_expression.get(), symbol_table, source_code, expressions);
    }
    if (additive_expression.additiveExpression) {
        if (additive_expression.additiveExpression.value().first && additive_expression.additiveExpression.value().first.value().second == ArithmeticSymbol::MINUS) {
            parseAdditiveExpression(*additive_expression.additiveExpression.value().second, symbol_table, source_code, expressions, sign * -1);
        } else {
            parseAdditiveExpression(*additive_expression.additiveExpression.value().second, symbol_table, source_code, expressions, sign);
        }
    }
}

} // namespace ast
