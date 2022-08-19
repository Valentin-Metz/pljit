#ifndef PLJIT_EXPRESSION_HPP
#define PLJIT_EXPRESSION_HPP

namespace ast {

class Expression {
    public:
    virtual ~Expression();
    enum ExpressionType {
        Additive,
        Multiplicative,
        Terminal,
    };
    const ExpressionType expressionType;

    protected:
    Expression(const ExpressionType expression_type);
};

} // namespace ast

#endif //PLJIT_EXPRESSION_HPP
