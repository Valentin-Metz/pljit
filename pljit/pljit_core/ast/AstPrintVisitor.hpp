#ifndef PLJIT_ASTPRINTVISITOR_HPP
#define PLJIT_ASTPRINTVISITOR_HPP

#include "AstVisitor.hpp"
namespace ast {

class AstPrintVisitor : public AstVisitor {
    public:
    ~AstPrintVisitor() override = default;
    virtual void visit(SymbolTable& node) override;
    virtual void visit(Function& node) override;
    virtual void visit(AssignmentStatement& node) override;
    virtual void visit(ReturnStatement& node) override;
    virtual void visit(AdditiveExpression& node) override;
    virtual void visit(MultiplicativeExpression& node) override;
    virtual void visit(TerminalExpression& node) override;
};

} // namespace ast

#endif //PLJIT_ASTPRINTVISITOR_HPP
