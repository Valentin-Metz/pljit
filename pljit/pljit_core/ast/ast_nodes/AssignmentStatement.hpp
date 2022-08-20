#ifndef PLJIT_ASSIGNMENTSTATEMENT_HPP
#define PLJIT_ASSIGNMENTSTATEMENT_HPP

#include "../../parse_tree/parse_tree_nodes/AssignmentExpression.hpp"
#include "../ast_core/ExecutionTable.hpp"
#include "../ast_core/SymbolTable.hpp"
#include "Statement.hpp"
namespace ast {

class AssignmentStatement : public Statement {
    public:
    const std::string_view target;
    AssignmentStatement(const parse_tree::AssignmentExpression* assignment_expression, SymbolTable& symbol_table, source_code::SourceCode& source_code);
    virtual void accept(AstVisitor& visitor) override;
    virtual void execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_ASSIGNMENTSTATEMENT_HPP
