#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP
#include "Expression.hpp"
#include <memory>
#include <vector>

namespace parse_tree {
class Statement;
}

namespace ast {

using parseTreeStatement = parse_tree::Statement;

class Statement {
    public:
    enum StatementType {
        Assignment,
        Return,
    };

    private:
    const StatementType statementType;
    std::vector<std::unique_ptr<Expression>> expressions;

    protected:
    Statement(StatementType statement_type, parse_tree::Statement statement);
};

} // namespace ast

#endif //PLJIT_STATEMENT_HPP
