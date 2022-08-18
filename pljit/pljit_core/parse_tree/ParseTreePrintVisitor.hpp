#ifndef PLJIT_PARSETREEPRINTVISITOR_HPP
#define PLJIT_PARSETREEPRINTVISITOR_HPP

#include "ParseTreeVisitor.hpp"
namespace parse_tree {

class ParseTreePrintVisitor : public ParseTreeVisitor {
    public:
    ~ParseTreePrintVisitor() override = default;
    void visit(const AdditiveExpression) const override;
    void visit(const AssignmentExpression) const override;
    void visit(const CompoundStatement) const override;
    void visit(const ConstantDeclaration) const override;
    void visit(const DeclaratorList) const override;
    void visit(const FunctionDefinition) const override;
    void visit(const Identifier) const override;
    void visit(const InitDeclarator) const override;
    void visit(const InitDeclaratorList) const override;
    void visit(const Literal) const override;
    void visit(const MultiplicativeExpression) const override;
    void visit(const ParameterDeclaration) const override;
    void visit(const PrimaryExpression) const override;
    void visit(const Statement) const override;
    void visit(const StatementList) const override;
    void visit(const TerminalSymbol) const override;
    void visit(const UnaryExpression) const override;
    void visit(const VariableDeclaration) const override;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREEPRINTVISITOR_HPP
