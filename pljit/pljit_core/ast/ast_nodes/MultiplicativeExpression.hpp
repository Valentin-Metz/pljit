#ifndef PLJIT_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_MULTIPLICATIVEEXPRESSION_HPP

#include "Expression.hpp"
#include <memory>
#include <vector>
namespace ast {

class MultiplicativeExpression : public Expression {
    public:
    std::vector<std::unique_ptr<Expression>> expressions;
    MultiplicativeExpression();
};

} // namespace ast

#endif //PLJIT_MULTIPLICATIVEEXPRESSION_HPP
