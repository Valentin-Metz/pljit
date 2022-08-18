#ifndef PLJIT_PARSETREESTATEMENT_HPP
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
    ~Statement();
    enum StatementType {
        Assignment,
        Return,
    };

    private:
    const StatementType statementType;
    std::vector<std::unique_ptr<Expression>> expressions;

    protected:
    Statement(StatementType statement_type, parse_tree::ParseTreeStatement statement);
};

} // namespace ast

#endif //PLJIT_PARSETREESTATEMENT_HPP
