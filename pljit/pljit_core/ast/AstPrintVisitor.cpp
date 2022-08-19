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

    std::cout << "AST -> SymbolTable\n";
    node.symbolTable.accept(*this);

    std::cout << "AST -> Function\n";
    node.function->accept(*this);

    std::cout << "}" << std::endl;
}

void AstPrintVisitor::visit(SymbolTable& node) {
    std::cout << "SymbolTable -> Parameters\n";
    std::cout << "SymbolTable -> Variables\n";
    std::cout << "SymbolTable -> Constants\n";

    for (auto& symbol : node.table) {
        switch (std::get<0>(symbol.second)) {
            case SymbolTable::Parameter: {
                std::cout << "Parameters -> " << symbol.first << "\n";
                break;
            }
            case SymbolTable::Variable: {
                std::cout << "Variables -> " << symbol.first << "\n";
                break;
            }
            case SymbolTable::Constant: {
                std::cout << "Constants -> " << symbol.first << "\n";
                std::cout << symbol.first << " -> " << std::get<2>(symbol.second) << "\n";
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
