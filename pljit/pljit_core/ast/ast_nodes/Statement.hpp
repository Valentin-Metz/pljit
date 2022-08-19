#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP
#include "../../parse_tree/parse_tree_nodes/AdditiveExpression.hpp"
#include "../SymbolTable.hpp"
#include "../ExecutionTable.hpp"
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
    virtual void accept(AstVisitor& visitor) = 0;
    virtual void execute(ExecutionTable& table) = 0;

    protected:
    Statement(StatementType statement_type);
};

} // namespace ast

#endif //PLJIT_STATEMENT_HPP
