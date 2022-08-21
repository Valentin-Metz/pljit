#ifndef PLJIT_EXPRESSION_HPP
#define PLJIT_EXPRESSION_HPP

#include <cstdint>
#include <memory>
#include <vector>
namespace ast {
class AstVisitor;
class ExecutionTable;

/// An expression evaluates to something
class Expression {
    public:
    virtual ~Expression();
    enum ExpressionType {
        Multiplicative,
        Terminal,
    };
    const ExpressionType expressionType;
    virtual void accept(AstVisitor& visitor) = 0;
    virtual int64_t execute(ExecutionTable& table) = 0;

    static std::int64_t evaluate_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ExecutionTable& table);

    protected:
    Expression(const ExpressionType expression_type);
};

} // namespace ast

#endif //PLJIT_EXPRESSION_HPP
