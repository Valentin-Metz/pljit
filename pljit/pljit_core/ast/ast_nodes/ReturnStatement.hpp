#ifndef PLJIT_RETURNSTATEMENT_HPP
#define PLJIT_RETURNSTATEMENT_HPP

#include "../../parse_tree/parse_tree_nodes/AdditiveExpression.hpp"
#include "../ExecutionTable.hpp"
#include "../SymbolTable.hpp"
#include "Statement.hpp"
namespace ast {

class ReturnStatement : public Statement {
    public:
    ReturnStatement(const parse_tree::AdditiveExpression* return_statement, SymbolTable& symbol_table, source_code::SourceCode& source_code);
    virtual void accept(AstVisitor& visitor) override;
    virtual void execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_RETURNSTATEMENT_HPP
