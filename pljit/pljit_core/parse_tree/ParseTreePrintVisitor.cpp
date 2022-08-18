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
    std::cout << "CompoundStatement -> Keyword_BEGIN_";
    node.begin.accept(*this);
    std::cout << "CompoundStatement -> StatementList";
    node.statementList.accept(*this);
}
void ParseTreePrintVisitor::visit(const ConstantDeclaration& node) const {
    std::cout << "ConstantDeclaration -> Keyword_CONST_";
    node.keyword.accept(*this);
    std::cout << "ConstantDeclaration -> InitDeclaratorList\n";
    node.initDeclaratorList.accept(*this);
}
void ParseTreePrintVisitor::visit(const DeclaratorList& node) const {
    std::cout << "DeclaratorList_" << node.declaratorList[0].first.identifier.source_code_reference.byte_index << "\n";
    for (std::size_t i = 0; i < node.declaratorList.size(); ++i) {
        std::cout << "DeclaratorList_" << node.declaratorList[0].first.identifier.source_code_reference.byte_index << " -> ";
        node.declaratorList[i].first.accept(*this);
        if (i != node.declaratorList.size() - 1) {
            std::cout << "DeclaratorList_" << node.declaratorList[0].first.identifier.source_code_reference.byte_index << " -> COMMA_";
        } else {
            std::cout << "DeclaratorList_" << node.declaratorList[0].first.identifier.source_code_reference.byte_index << " -> SEMICOLON_";
        }
        node.declaratorList[i].second.accept(*this);
    }
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
    std::cout << "Terminator -> DOT_";
    node.terminator->accept(*this);

    std::cout << "}" << std::endl;
}
void ParseTreePrintVisitor::visit(const Identifier& node) const {
    std::cout << "Identifier_";
    node.identifier.accept(*this);
}
void ParseTreePrintVisitor::visit(const InitDeclarator& node) const {
    std::cout << "InitDeclarator_" << node.identifier.identifier.source_code_reference.byte_index << "\n";
    std::cout << "InitDeclarator_" << node.identifier.identifier.source_code_reference.byte_index << " -> ";
    node.identifier.accept(*this);
    std::cout << "InitDeclarator_" << node.identifier.identifier.source_code_reference.byte_index << " -> AssignmentOperator_";
    node.assignment_symbol.accept(*this);
    std::cout << "InitDeclarator_" << node.identifier.identifier.source_code_reference.byte_index << " -> ";
    node.literal.accept(*this);
}
void ParseTreePrintVisitor::visit(const InitDeclaratorList& node) const {
    for (std::size_t i = 0; i < node.initDeclaratorList.size(); ++i) {
        std::cout << "InitDeclaratorList -> ";
        node.initDeclaratorList[i].first.accept(*this);
        if (i != node.initDeclaratorList.size() - 1) {
            std::cout << "InitDeclaratorList -> COMMA_";
        } else {
            std::cout << "InitDeclaratorList -> SEMICOLON_";
        }
        node.initDeclaratorList[i].second.accept(*this);
    }
}
void ParseTreePrintVisitor::visit(const Literal& node) const {
    std::cout << "Literal_" << node.literal.second << "_" << node.literal.first.source_code_reference.byte_index << "\n";
}
void ParseTreePrintVisitor::visit(const MultiplicativeExpression& node) const {
}
void ParseTreePrintVisitor::visit(const ParameterDeclaration& node) const {
    std::cout << "ParameterDeclaration -> Keyword_PARAM_";
    node.keyword.accept(*this);
    std::cout << "ParameterDeclaration -> ";
    node.declaratorList.accept(*this);
}
void ParseTreePrintVisitor::visit(const PrimaryExpression& node) const {
}
void ParseTreePrintVisitor::visit(const Statement& node) const {
}
void ParseTreePrintVisitor::visit(const StatementList& node) const {
    for (std::size_t i = 0; i < node.statementList.size(); ++i) {
        std::cout << "StatementList -> ";
        node.statementList[i].first.get()->accept(*this);
        if (i != node.statementList.size() - 1) {
            std::cout << "StatementList -> SEMICOLON_";
        } else {
            std::cout << "StatementList -> Keyword_END_";
        }
        node.statementList[i].second.accept(*this);
    }
}
void ParseTreePrintVisitor::visit(const TerminalSymbol& node) const {
    std::cout << node.source_code_reference.byte_index << "\n";
}
void ParseTreePrintVisitor::visit(const UnaryExpression& node) const {
}
void ParseTreePrintVisitor::visit(const VariableDeclaration& node) const {
    std::cout << "VariableDeclaration-> Keyword_VAR_";
    node.keyword.accept(*this);
    std::cout << "VariableDeclaration -> ";
    node.declaratorList.accept(*this);
}
} // namespace parse_tree