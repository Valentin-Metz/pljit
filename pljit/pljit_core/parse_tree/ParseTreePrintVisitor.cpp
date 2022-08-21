#include "ParseTreePrintVisitor.hpp"
#include "parse_tree_nodes/AdditiveExpression.hpp"
#include "parse_tree_nodes/ArithmeticSymbol.hpp"
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
    size_t identifier = 0;
    if (node.unaryExpression.modifier) {
        identifier = node.unaryExpression.modifier.value().first.source_code_reference.byte_index;
    } else {
        if (node.unaryExpression.primaryExpression.value()->identifier) {
            identifier = node.unaryExpression.primaryExpression.value()->identifier->identifier.source_code_reference.byte_index;
        }
        if (node.unaryExpression.primaryExpression.value()->literal) {
            identifier = node.unaryExpression.primaryExpression.value()->literal.value().literal.first.source_code_reference.byte_index;
        }
        if (node.unaryExpression.primaryExpression.value()->openBracket) {
            identifier = node.unaryExpression.primaryExpression.value()->openBracket->source_code_reference.byte_index;
        }
    }
    std::cout << "AdditiveExpression_" << identifier << "\n";
    std::cout << "AdditiveExpression_" << identifier << " -> ";
    node.unaryExpression.accept(*this);
    for (std::size_t i = 0; i < node.multiplicativeExpression.size(); ++i) {
        std::cout << "AdditiveExpression_" << identifier << " -> ";
        node.multiplicativeExpression[i]->accept(*this);
    }
    if (node.additiveExpression) {
        if (node.additiveExpression->first) {
            std::cout << "AdditiveExpression_" << identifier << " -> ";
            if (node.additiveExpression->first.value().second == ArithmeticSymbol::PLUS) {
                std::cout << "ArithmeticSymbol_PLUS_";
            } else {
                std::cout << "ArithmeticSymbol_MINUS_";
            }
            node.additiveExpression->first.value().first.accept(*this);
        }
        std::cout << "AdditiveExpression_" << identifier << " -> ";
        node.additiveExpression->second->accept(*this);
    }
}

void ParseTreePrintVisitor::visit(const AssignmentExpression& node) const {
    std::cout << "AssignmentExpression_" << node.identifier.identifier.source_code_reference.byte_index << "\n";
    std::cout << "AssignmentExpression_" << node.identifier.identifier.source_code_reference.byte_index << " -> ";
    node.identifier.accept(*this);
    std::cout << "AssignmentExpression_" << node.identifier.identifier.source_code_reference.byte_index << " -> ";
    std::cout << "AssignmentOperator_";
    node.assignmentToken.accept(*this);
    std::cout << "AssignmentExpression_" << node.identifier.identifier.source_code_reference.byte_index << " -> ";
    node.additiveExpression.accept(*this);
}

void ParseTreePrintVisitor::visit(const CompoundStatement& node) const {
    std::cout << "CompoundStatement -> Keyword_BEGIN_";
    node.begin.accept(*this);
    std::cout << "CompoundStatement -> StatementList\n";
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
    std::cout << "InitDeclarator_" << node.identifier.identifier.source_code_reference.byte_index << " -> DeclarationOperator_";
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
    std::cout << "MultiplicativeExpression_" << node.multiplicativeOperator.first.source_code_reference.byte_index << "\n";

    std::cout << "MultiplicativeExpression_" << node.multiplicativeOperator.first.source_code_reference.byte_index << " -> ";
    if (node.multiplicativeOperator.second== ArithmeticSymbol::MULTIPLY){
        std::cout <<"ArithmeticSymbol_MULTIPLY_";
    } else{
        std::cout <<"ArithmeticSymbol_DIVIDE_";
    }
    node.multiplicativeOperator.first.accept(*this);

    std::cout << "MultiplicativeExpression_" << node.multiplicativeOperator.first.source_code_reference.byte_index << " -> ";
    node.unaryExpression.accept(*this);
}

void ParseTreePrintVisitor::visit(const ParameterDeclaration& node) const {
    std::cout << "ParameterDeclaration -> Keyword_PARAM_";
    node.keyword.accept(*this);
    std::cout << "ParameterDeclaration -> ";
    node.declaratorList.accept(*this);
}

void ParseTreePrintVisitor::visit(const PrimaryExpression& node) const {
    size_t identifier = 0;
    if (node.identifier) {
        identifier = node.identifier->identifier.source_code_reference.byte_index;
    }
    if (node.literal) {
        identifier = node.literal.value().literal.first.source_code_reference.byte_index;
    }
    if (node.openBracket) {
        identifier = node.openBracket->source_code_reference.byte_index;
    }

    std::cout << "PrimaryExpression_" << identifier << "\n";

    if (node.openBracket) {
        std::cout << "PrimaryExpression_" << identifier << " -> ";
        std::cout << "Bracket_OPEN_";
        node.openBracket->accept(*this);
    }
    if (node.closingBracket) {
        std::cout << "PrimaryExpression_" << identifier << " -> ";
        std::cout << "Bracket_CLOSE_";
        node.closingBracket->accept(*this);
    }

    if (node.identifier) {
        std::cout << "PrimaryExpression_" << identifier << " -> ";
        node.identifier.value().accept(*this);
    }
    if (node.literal) {
        std::cout << "PrimaryExpression_" << identifier << " -> ";
        node.literal->accept(*this);
    }
    if (node.additiveExpression) {
        std::cout << "PrimaryExpression_" << identifier << " -> ";
        node.additiveExpression.value()->accept(*this);
    }
}

void ParseTreePrintVisitor::visit(const Statement& node) const {
    std::cout << "Statement_";
    if (node.assignmentExpression) {
        std::cout << node.assignmentExpression.value()->identifier.identifier.source_code_reference.byte_index << "\n";
        std::cout << "Statement_" << node.assignmentExpression.value()->identifier.identifier.source_code_reference.byte_index << " -> ";
        node.assignmentExpression.value()->accept(*this);
    } else {
        std::cout << node.additiveExpression.value().first->source_code_reference.byte_index << "\n";
        std::cout << "Statement_" << node.additiveExpression.value().first->source_code_reference.byte_index << " -> Keyword_RETURN_";
        node.additiveExpression.value().first->accept(*this);
        std::cout << "Statement_" << node.additiveExpression.value().first->source_code_reference.byte_index << " -> ";
        node.additiveExpression.value().second->accept(*this);
    }
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
    size_t identifier = 0;
    if (node.modifier) {
        identifier = node.modifier.value().first.source_code_reference.byte_index;
    } else {
        if (node.primaryExpression.value()->identifier) {
            identifier = node.primaryExpression.value()->identifier->identifier.source_code_reference.byte_index;
        }
        if (node.primaryExpression.value()->literal) {
            identifier = node.primaryExpression.value()->literal.value().literal.first.source_code_reference.byte_index;
        }
        if (node.primaryExpression.value()->openBracket) {
            identifier = node.primaryExpression.value()->openBracket->source_code_reference.byte_index;
        }
    }
    std::cout << "UnaryExpression_" << identifier << "\n";

    if (node.modifier) {
        std::cout << "UnaryExpression_" << identifier << " -> ";
        if (node.modifier.value().second == ArithmeticSymbol::PLUS) {
            std::cout << "ArithmeticSymbol_PLUS_";
        } else {
            std::cout << "ArithmeticSymbol_MINUS_";
        }
        node.modifier.value().first.accept(*this);
    }
    std::cout << "UnaryExpression_" << identifier << " -> ";
    node.primaryExpression.value()->accept(*this);
}

void ParseTreePrintVisitor::visit(const VariableDeclaration& node) const {
    std::cout << "VariableDeclaration-> Keyword_VAR_";
    node.keyword.accept(*this);
    std::cout << "VariableDeclaration -> ";
    node.declaratorList.accept(*this);
}

} // namespace parse_tree
