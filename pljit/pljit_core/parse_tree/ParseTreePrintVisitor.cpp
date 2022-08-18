#include "ParseTreePrintVisitor.hpp"
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
void ParseTreePrintVisitor::visit(const AdditiveExpression& node) const {
}
void ParseTreePrintVisitor::visit(const AssignmentExpression& node) const {
}
void ParseTreePrintVisitor::visit(const CompoundStatement& node) const {
}
void ParseTreePrintVisitor::visit(const ConstantDeclaration& node) const {
}
void ParseTreePrintVisitor::visit(const DeclaratorList& node) const {
}
void ParseTreePrintVisitor::visit(const FunctionDefinition& node) const {
}
void ParseTreePrintVisitor::visit(const Identifier& node) const {
}
void ParseTreePrintVisitor::visit(const InitDeclarator& node) const {
}
void ParseTreePrintVisitor::visit(const InitDeclaratorList& node) const {
}
void ParseTreePrintVisitor::visit(const Literal& node) const {
}
void ParseTreePrintVisitor::visit(const MultiplicativeExpression& node) const {
}
void ParseTreePrintVisitor::visit(const ParameterDeclaration& node) const {
}
void ParseTreePrintVisitor::visit(const PrimaryExpression& node) const {
}
void ParseTreePrintVisitor::visit(const Statement& node) const {
}
void ParseTreePrintVisitor::visit(const StatementList& node) const {
}
void ParseTreePrintVisitor::visit(const TerminalSymbol& node) const {
}
void ParseTreePrintVisitor::visit(const UnaryExpression& node) const {
}
void ParseTreePrintVisitor::visit(const VariableDeclaration& node) const {
}
} // namespace parse_tree