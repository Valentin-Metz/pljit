#ifndef PLJIT_ASTVISITOR_HPP
#define PLJIT_ASTVISITOR_HPP

namespace ast {

class AST;
class SymbolTable;
class Function;
class AssignmentStatement;
class ReturnStatement;
class MultiplicativeExpression;
class TerminalExpression;

class AstVisitor {
    public:
    virtual ~AstVisitor() = default;
    virtual void visit(AST& node) = 0;
    virtual void visit(SymbolTable& node) = 0;
    virtual void visit(Function& node) = 0;
    virtual void visit(AssignmentStatement& node) = 0;
    virtual void visit(ReturnStatement& node) = 0;
    virtual void visit(MultiplicativeExpression& node) = 0;
    virtual void visit(TerminalExpression& node) = 0;
};

} // namespace ast

#endif //PLJIT_ASTVISITOR_HPP
