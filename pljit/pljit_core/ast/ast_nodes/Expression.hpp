#ifndef PLJIT_EXPRESSION_HPP
#define PLJIT_EXPRESSION_HPP

namespace ast {
class AstVisitor;

class Expression {
    public:
    virtual ~Expression();
    enum ExpressionType {
        Additive,
        Multiplicative,
        Terminal,
    };
    const ExpressionType expressionType;
    virtual void accept(AstVisitor& visitor) = 0;

    protected:
    Expression(const ExpressionType expression_type);
};

} // namespace ast

#endif //PLJIT_EXPRESSION_HPP
