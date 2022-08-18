#ifndef PLJIT_PARSETREEVISITOR_HPP
#define PLJIT_PARSETREEVISITOR_HPP

#include "parse_tree_nodes/AdditiveExpression.hpp"
#include "parse_tree_nodes/AssignmentExpression.hpp"
#include "parse_tree_nodes/CompoundStatement.hpp"
#include "parse_tree_nodes/ConstantDeclaration.hpp"
#include "parse_tree_nodes/DeclaratorList.hpp"
#include "parse_tree_nodes/FunctionDefinition.hpp"
#include "parse_tree_nodes/Identifier.hpp"
#include "parse_tree_nodes/InitDeclarator.hpp"
#include "parse_tree_nodes/InitDeclaratorList.hpp"
#include "parse_tree_nodes/Literal.hpp"
#include "parse_tree_nodes/MultiplicativeExpression.hpp"
#include "parse_tree_nodes/ParameterDeclaration.hpp"
#include "parse_tree_nodes/PrimaryExpression.hpp"
#include "parse_tree_nodes/Statement.hpp"
#include "parse_tree_nodes/StatementList.hpp"
#include "parse_tree_nodes/TerminalSymbol.hpp"
#include "parse_tree_nodes/UnaryExpression.hpp"
#include "parse_tree_nodes/VariableDeclaration.hpp"
namespace parse_tree {

class ParseTreeVisitor {
    public:
    virtual ~ParseTreeVisitor() = default;
    virtual void visit(const AdditiveExpression) const = 0;
    virtual void visit(const AssignmentExpression) const = 0;
    virtual void visit(const CompoundStatement) const = 0;
    virtual void visit(const ConstantDeclaration) const = 0;
    virtual void visit(const DeclaratorList) const = 0;
    virtual void visit(const FunctionDefinition) const = 0;
    virtual void visit(const Identifier) const = 0;
    virtual void visit(const InitDeclarator) const = 0;
    virtual void visit(const InitDeclaratorList) const = 0;
    virtual void visit(const Literal) const = 0;
    virtual void visit(const MultiplicativeExpression) const = 0;
    virtual void visit(const ParameterDeclaration) const = 0;
    virtual void visit(const PrimaryExpression) const = 0;
    virtual void visit(const Statement) const = 0;
    virtual void visit(const StatementList) const = 0;
    virtual void visit(const TerminalSymbol) const = 0;
    virtual void visit(const UnaryExpression) const = 0;
    virtual void visit(const VariableDeclaration) const = 0;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREEVISITOR_HPP
