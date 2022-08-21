#ifndef PLJIT_RETURNSTATEMENT_HPP
#define PLJIT_RETURNSTATEMENT_HPP

#include "Statement.hpp"
#include "ast/ast_core/ExecutionTable.hpp"
#include "ast/ast_core/SymbolTable.hpp"
#include "parse_tree/parse_tree_nodes/AdditiveExpression.hpp"
namespace ast {

/// A return statement returns the the final value a function evaluates to
class ReturnStatement : public Statement {
    public:
    ReturnStatement(const parse_tree::AdditiveExpression* return_statement, SymbolTable& symbol_table, source_code::SourceCode& source_code);
    virtual void accept(AstVisitor& visitor) override;
    virtual void execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_RETURNSTATEMENT_HPP
