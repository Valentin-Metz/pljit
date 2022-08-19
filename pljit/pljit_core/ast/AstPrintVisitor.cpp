#include "AstPrintVisitor.hpp"
#include "Ast.hpp"
#include "SymbolTable.hpp"
#include "ast_nodes/AdditiveExpression.hpp"
#include "ast_nodes/AssignmentStatement.hpp"
#include "ast_nodes/Function.hpp"
#include "ast_nodes/MultiplicativeExpression.hpp"
#include "ast_nodes/ReturnStatement.hpp"
#include "ast_nodes/TerminalExpression.hpp"
#include <iostream>
#include <tuple>

namespace ast {

void AstPrintVisitor::visit(AST& node) {
    std::cout << "digraph AST {\n";

    node.symbolTable.accept(*this);

    std::cout << "}" << std::endl;
}

void AstPrintVisitor::visit(SymbolTable& node) {
    for (auto& symbol : node.table) {
        std::cout << "SymbolTable -> ";

        switch (std::get<0>(symbol.second)) {
            case SymbolTable::Parameter: {
                std::cout << "Parameter_" << symbol.first << "\n";
                break;
            }
            case SymbolTable::Variable: {
                std::cout << "Variable_" << symbol.first << "\n";
                break;
            }
            case SymbolTable::Constant: {
                std::cout << "Constant_" << symbol.first << "\n";
                std::cout << "Constant_" << symbol.first << " -> " << std::get<2>(symbol.second) << "\n";
                break;
            }
        }
    }
}

void AstPrintVisitor::visit(Function& node) {
}

void AstPrintVisitor::visit(AssignmentStatement& node) {
}

void AstPrintVisitor::visit(ReturnStatement& node) {
}

void AstPrintVisitor::visit(AdditiveExpression& node) {
}

void AstPrintVisitor::visit(MultiplicativeExpression& node) {
}

void AstPrintVisitor::visit(TerminalExpression& node) {
}

} // namespace ast
