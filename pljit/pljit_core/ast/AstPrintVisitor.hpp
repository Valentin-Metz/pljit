#ifndef PLJIT_ASTPRINTVISITOR_HPP
#define PLJIT_ASTPRINTVISITOR_HPP

#include "AstVisitor.hpp"
#include <cstdlib>
namespace ast {

class AstPrintVisitor : public AstVisitor {
    private:
    std::size_t statement_counter = 0;
    std::size_t expression_counter = 0;

    public:
    ~AstPrintVisitor() override = default;
    virtual void visit(AST& node) override;
    virtual void visit(SymbolTable& node) override;
    virtual void visit(Function& node) override;
    virtual void visit(AssignmentStatement& node) override;
    virtual void visit(ReturnStatement& node) override;
    virtual void visit(MultiplicativeExpression& node) override;
    virtual void visit(TerminalExpression& node) override;
};

} // namespace ast

#endif //PLJIT_ASTPRINTVISITOR_HPP
