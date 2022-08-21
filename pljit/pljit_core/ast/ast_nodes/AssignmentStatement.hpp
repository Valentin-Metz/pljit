#ifndef PLJIT_ASSIGNMENTSTATEMENT_HPP
#define PLJIT_ASSIGNMENTSTATEMENT_HPP

#include "Statement.hpp"
#include "parse_tree/parse_tree_nodes/AssignmentExpression.hpp"
namespace ast {
class ExecutionTable;
class SymbolTable;

/// Statement that assigns a variable
class AssignmentStatement : public Statement {
    public:
    const std::string_view target;
    AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code);
    virtual void accept(AstVisitor& visitor) override;
    virtual void execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_ASSIGNMENTSTATEMENT_HPP
