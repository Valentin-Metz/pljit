#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP
#include <memory>
#include <vector>

namespace parse_tree {
class ParseTreeStatement;
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

    private:
    const StatementType statementType;
    std::vector<std::unique_ptr<Expression>> expressions;

    protected:
    Statement(StatementType statement_type);
};

} // namespace ast

#endif //PLJIT_STATEMENT_HPP
