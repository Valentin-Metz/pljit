#ifndef PLJIT_ADDITIVEEXPRESSION_HPP
#define PLJIT_ADDITIVEEXPRESSION_HPP

#include "Expression.hpp"
namespace ast {
class AstVisitor;

class AdditiveExpression : public Expression {
    public:
    AdditiveExpression();
    virtual void accept(AstVisitor& visitor) override;
};

} // namespace ast

#endif //PLJIT_ADDITIVEEXPRESSION_HPP
