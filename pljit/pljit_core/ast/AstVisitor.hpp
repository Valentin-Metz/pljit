#ifndef PLJIT_ASTVISITOR_HPP
#define PLJIT_ASTVISITOR_HPP

namespace ast {

class SymbolTable;
class Function;
class Statement;
class Expression;

class AstVisitor {
    public:
    virtual ~AstVisitor() = default;
    virtual void visit(const SymbolTable& node) const = 0;
    virtual void visit(const Function& node) const = 0;
    virtual void visit(const Statement& node) const = 0;
    virtual void visit(const Expression& node) const = 0;
};

} // namespace ast

#endif //PLJIT_ASTVISITOR_HPP
