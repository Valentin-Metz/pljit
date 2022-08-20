#ifndef PLJIT_ASTOPTIMIZATIONVISITOR_HPP
#define PLJIT_ASTOPTIMIZATIONVISITOR_HPP

#include "../ast_core/AstVisitor.hpp"
namespace ast {

class AstOptimizationVisitor : public AstVisitor{
    public:
    ~AstOptimizationVisitor() override = default;
    virtual void visit(AST& node) override;
    virtual void visit(SymbolTable& node) override;
    virtual void visit(Function& node) override;
    virtual void visit(AssignmentStatement& node) override;
    virtual void visit(ReturnStatement& node) override;
    virtual void visit(MultiplicativeExpression& node) override;
    virtual void visit(TerminalExpression& node) override;
};

} // namespace ast

#endif //PLJIT_ASTOPTIMIZATIONVISITOR_HPP
