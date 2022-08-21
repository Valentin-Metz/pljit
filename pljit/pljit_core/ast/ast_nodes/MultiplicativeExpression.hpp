#ifndef PLJIT_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_MULTIPLICATIVEEXPRESSION_HPP

#include "Expression.hpp"
#include "ast/ast_core/SymbolTable.hpp"
#include <memory>
#include <vector>
namespace ast {

/// A multiplicative expression contains a list of expressions that must be evaluated before it can be used as an operand
class MultiplicativeExpression : public Expression {
    public:
    enum MultiplicativeOperator {
        Multiply,
        Divide,
    };
    const MultiplicativeOperator multiplicativeOperator;

    // List of contained expressions
    std::vector<std::unique_ptr<Expression>> expressions;

    /// Construction requires an operator (multiply/divide) and a reference to the unary expression it will use to construct itself
    MultiplicativeExpression(MultiplicativeOperator multiplicative_operator, const parse_tree::UnaryExpression& additive_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code);

    // Visitor
    virtual void accept(AstVisitor& visitor) override;
    // Execution
    virtual int64_t execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_MULTIPLICATIVEEXPRESSION_HPP
