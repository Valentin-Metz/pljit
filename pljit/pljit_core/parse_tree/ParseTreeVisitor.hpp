#ifndef PLJIT_PARSETREEVISITOR_HPP
#define PLJIT_PARSETREEVISITOR_HPP

namespace parse_tree {

class AdditiveExpression;
class AssignmentExpression;
class CompoundStatement;
class ConstantDeclaration;
class DeclaratorList;
class FunctionDefinition;
class Identifier;
class InitDeclarator;
class InitDeclaratorList;
class Literal;
class MultiplicativeExpression;
class ParameterDeclaration;
class PrimaryExpression;
class ParseTreeStatement;
class StatementList;
class TerminalSymbol;
class UnaryExpression;
class VariableDeclaration;

class ParseTreeVisitor {
    public:
    virtual ~ParseTreeVisitor() = default;
    virtual void visit(const AdditiveExpression& node) const = 0;
    virtual void visit(const AssignmentExpression& node) const = 0;
    virtual void visit(const CompoundStatement& node) const = 0;
    virtual void visit(const ConstantDeclaration& node) const = 0;
    virtual void visit(const DeclaratorList& node) const = 0;
    virtual void visit(const FunctionDefinition& node) const = 0;
    virtual void visit(const Identifier& node) const = 0;
    virtual void visit(const InitDeclarator& node) const = 0;
    virtual void visit(const InitDeclaratorList& node) const = 0;
    virtual void visit(const Literal& node) const = 0;
    virtual void visit(const MultiplicativeExpression& node) const = 0;
    virtual void visit(const ParameterDeclaration& node) const = 0;
    virtual void visit(const PrimaryExpression& node) const = 0;
    virtual void visit(const ParseTreeStatement& node) const = 0;
    virtual void visit(const StatementList& node) const = 0;
    virtual void visit(const TerminalSymbol& node) const = 0;
    virtual void visit(const UnaryExpression& node) const = 0;
    virtual void visit(const VariableDeclaration& node) const = 0;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREEVISITOR_HPP
