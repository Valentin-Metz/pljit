#ifndef PLJIT_ASSIGNMENTSTATEMENT_HPP
#define PLJIT_ASSIGNMENTSTATEMENT_HPP

#include "../../parse_tree/parse_tree_nodes/AssignmentExpression.hpp"
#include "Statement.hpp"
namespace ast {

class AssignmentStatement : public Statement {
    public:
    AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression);
};

} // namespace ast

#endif //PLJIT_ASSIGNMENTSTATEMENT_HPP
