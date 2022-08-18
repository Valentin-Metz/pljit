#ifndef PLJIT_RETURNSTATEMENT_HPP
#define PLJIT_RETURNSTATEMENT_HPP

#include "Statement.hpp"
#include "../../parse_tree/parse_tree_nodes/AdditiveExpression.hpp"
namespace ast {

class ReturnStatement : public Statement {
    public:
    ReturnStatement(const parse_tree::AdditiveExpression* statement);
};

} // namespace ast

#endif //PLJIT_RETURNSTATEMENT_HPP
