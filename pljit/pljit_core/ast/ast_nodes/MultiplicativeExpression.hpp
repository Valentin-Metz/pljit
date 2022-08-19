#ifndef PLJIT_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_MULTIPLICATIVEEXPRESSION_HPP

#include "../SymbolTable.hpp"
#include "Expression.hpp"
#include <memory>
#include <vector>
namespace ast {

class MultiplicativeExpression : public Expression {
    public:
    enum MultiplicativeOperator {
        Multiply,
        Divide,
    };
    const MultiplicativeOperator multiplicativeOperator;
    std::vector<std::unique_ptr<Expression>> expressions;
    MultiplicativeExpression(MultiplicativeOperator multiplicative_operator, const parse_tree::UnaryExpression& additive_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code);
};

} // namespace ast

#endif //PLJIT_MULTIPLICATIVEEXPRESSION_HPP
