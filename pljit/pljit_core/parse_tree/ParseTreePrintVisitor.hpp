#ifndef PLJIT_PARSETREEPRINTVISITOR_HPP
#define PLJIT_PARSETREEPRINTVISITOR_HPP

#include "ParseTreeVisitor.hpp"
namespace parse_tree {

class ParseTreePrintVisitor : public ParseTreeVisitor {
    public:
    ~ParseTreePrintVisitor() override = default;
    void visit(const AdditiveExpression& node) const override;
    void visit(const AssignmentExpression& node) const override;
    void visit(const CompoundStatement& node) const override;
    void visit(const ConstantDeclaration& node) const override;
    void visit(const DeclaratorList& node) const override;
    void visit(const FunctionDefinition& node) const override;
    void visit(const Identifier& node) const override;
    void visit(const InitDeclarator& node) const override;
    void visit(const InitDeclaratorList& node) const override;
    void visit(const Literal& node) const override;
    void visit(const MultiplicativeExpression& node) const override;
    void visit(const ParameterDeclaration& node) const override;
    void visit(const PrimaryExpression& node) const override;
    void visit(const ParseTreeStatement& node) const override;
    void visit(const StatementList& node) const override;
    void visit(const TerminalSymbol& node) const override;
    void visit(const UnaryExpression& node) const override;
    void visit(const VariableDeclaration& node) const override;
    public:
};

} // namespace parse_tree

#endif //PLJIT_PARSETREEPRINTVISITOR_HPP
