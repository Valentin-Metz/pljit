#include "Statement.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "Expression.hpp"

namespace ast {
Statement::~Statement() {
}
Statement::Statement(Statement::StatementType statement_type) : statementType(statement_type) {
}

static void parseUnaryExpression(const parse_tree::UnaryExpression& unary_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign) {
}

static void parseMultiplicativeExpression(const parse_tree::MultiplicativeExpression* multiplicative_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions) {
}

void Statement::parseAdditiveExpression(const parse_tree::AdditiveExpression& additive_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign) {
    parseUnaryExpression(additive_expression.unaryExpression, symbol_table, source_code, expressions, sign);
    for (auto& multiplicative_expression : additive_expression.multiplicativeExpression) {
        parseMultiplicativeExpression(multiplicative_expression.get(), symbol_table, source_code, expressions);
    }
}

} // namespace ast