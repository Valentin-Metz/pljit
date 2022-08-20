#ifndef PLJIT_EXPRESSION_HPP
#define PLJIT_EXPRESSION_HPP

#include "../ast_core/ExecutionTable.hpp"
#include <cstdint>
namespace ast {
class AstVisitor;

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

    protected:
    Expression(const ExpressionType expression_type);
};

} // namespace ast

#endif //PLJIT_EXPRESSION_HPP
