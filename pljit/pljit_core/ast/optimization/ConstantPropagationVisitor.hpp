#ifndef PLJIT_CONSTANTPROPAGATIONVISITOR_HPP
#define PLJIT_CONSTANTPROPAGATIONVISITOR_HPP

#include "ast/ast_core/AstVisitor.hpp"
#include <string_view>
#include <unordered_map>
namespace ast {

class ConstantPropagationVisitor : AstVisitor {
    private:
    std::unordered_map<std::string_view, std::int64_t> constant_identifiers;

    public:
    ~ConstantPropagationVisitor() override = default;
    virtual void visit(AST& node) override;
    virtual void visit(SymbolTable& node) override;
    virtual void visit(Function& node) override;
    virtual void visit(AssignmentStatement& node) override;
    virtual void visit(ReturnStatement& node) override;
    virtual void visit(MultiplicativeExpression& node) override;
    virtual void visit(TerminalExpression& node) override;
};

} // namespace ast

#endif //PLJIT_CONSTANTPROPAGATIONVISITOR_HPP
