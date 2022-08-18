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
#include <iostream>

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
    std::cout << "digraph ParseTree {\n";

    if (node.parameter_declaration) {
        std::cout << "FunctionDefinition -> ParameterDeclaration\n";
        node.parameter_declaration->accept(*this);
    }
    if (node.variable_declaration) {
        std::cout << "FunctionDefinition -> VariableDeclaration\n";
        node.variable_declaration->accept(*this);
    }
    if (node.constant_declaration) {
        std::cout << "FunctionDefinition -> ConstantDeclaration\n";
        node.constant_declaration->accept(*this);
    }

    std::cout << "FunctionDefinition -> CompoundStatement\n";
    node.compound_statement->accept(*this);
    std::cout << "FunctionDefinition -> Terminator\n";
    std::cout << "Terminator -> DOT";
    node.terminator->accept(*this);

    std::cout << "}" << std::endl;
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
    std::cout << node.source_code_reference.byte_index << "\n";
}
void ParseTreePrintVisitor::visit(const UnaryExpression& node) const {
}
void ParseTreePrintVisitor::visit(const VariableDeclaration& node) const {
}
} // namespace parse_tree