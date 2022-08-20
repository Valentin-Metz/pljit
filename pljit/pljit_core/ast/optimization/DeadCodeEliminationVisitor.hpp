#ifndef PLJIT_DEADCODEELIMINATIONVISITOR_HPP
#define PLJIT_DEADCODEELIMINATIONVISITOR_HPP

#include "ast/ast_core/AstVisitor.hpp"

namespace ast {

class DeadCodeEliminationVisitor : public AstVisitor {
    public:
    ~DeadCodeEliminationVisitor() override = default;
    virtual void visit(AST& node) override;
    virtual void visit(SymbolTable& node) override;
    virtual void visit(Function& node) override;
    virtual void visit(AssignmentStatement& node) override;
    virtual void visit(ReturnStatement& node) override;
    virtual void visit(MultiplicativeExpression& node) override;
    virtual void visit(TerminalExpression& node) override;
};

} // namespace ast

#endif //PLJIT_DEADCODEELIMINATIONVISITOR_HPP
