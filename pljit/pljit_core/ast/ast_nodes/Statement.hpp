#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP
#include "../../parse_tree/parse_tree_nodes/AdditiveExpression.hpp"
#include "../SymbolTable.hpp"
#include <memory>
#include <vector>

namespace parse_tree {
class Statement;
}

namespace ast {
class Expression;

class Statement {
    public:
    virtual ~Statement();
    enum StatementType {
        Assignment,
        Return,
    };
    const StatementType statementType;
    std::vector<std::unique_ptr<Expression>> expressions;
    static void parseAdditiveExpression(const parse_tree::AdditiveExpression& additive_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign);
    static void parseUnaryExpression(const parse_tree::UnaryExpression& unary_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code, std::vector<std::unique_ptr<Expression>>& expressions, int64_t sign);

    protected:
    Statement(StatementType statement_type);
};

} // namespace ast

#endif //PLJIT_STATEMENT_HPP
