#include "AstPrintVisitor.hpp"
#include "Ast.hpp"
#include "SymbolTable.hpp"
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
    for (auto& statement : node.statements) {
        std::cout << "Function -> Statement_" << statement_counter << "\n";
        statement.get()->accept(*this);
        statement_counter++;
    }
}

void AstPrintVisitor::visit(AssignmentStatement& node) {
    std::cout << "Statement_" << statement_counter << " -> ASSIGN_" << statement_counter << " [color=purple]\n";
    std::cout << "ASSIGN_" << statement_counter << " [label = \"ASSIGN\"]\n";
    std::cout << "ASSIGN_" << statement_counter << " -> " << node.target << "_" << unique_counter << " [color=purple]\n";
    std::cout << node.target << "_" << unique_counter-- << " [label = \"" << node.target << "\"]\n";

    if (!node.expressions.empty()) {
        std::cout << "Statement_" << statement_counter << " -> ";
    }
    printExpressions(node.expressions);
}

void AstPrintVisitor::visit(ReturnStatement& node) {
    std::cout << "Statement_" << statement_counter << " -> RETURN_" << statement_counter << " [color=pink]\n";
    std::cout << "RETURN_" << statement_counter << " [label = \"RETURN\"]\n";

    if (!node.expressions.empty()) {
        std::cout << "Statement_" << statement_counter << " -> ";
    }
    printExpressions(node.expressions);
}

void AstPrintVisitor::visit(MultiplicativeExpression& node) {
    if (node.multiplicativeOperator == MultiplicativeExpression::Multiply) {
        std::cout << "MULTIPLY_" << unique_counter << " [color=green]\n";
        std::cout << "MULTIPLY_" << unique_counter << " [label = \"*\"]\n";
        std::cout << "MULTIPLY_" << unique_counter-- << " -> MultiplicativeExpression_" << expression_counter << " [color=green]\n";
    } else {
        std::cout << "DIVIDE_" << unique_counter << " [color=lightblue]\n";
        std::cout << "DIVIDE_" << unique_counter << " [label = \"*\"]\n";
        std::cout << "DIVIDE_" << unique_counter-- << " -> MultiplicativeExpression_" << expression_counter << " [color=lightblue]\n";
    }
    if (!node.expressions.empty()) {
        std::cout << "MultiplicativeExpression_" << expression_counter << " -> ";
    }
    printExpressions(node.expressions);
}

void AstPrintVisitor::visit(TerminalExpression& node) {
    if (node.value.index() == 0) {
        std::cout << std::get<int64_t>(node.value) << "\n";
    } else {
        auto value = std::get<std::pair<int64_t, std::string_view>>(node.value);
        if (value.first == -1) {
            std::cout << "MINUS_" << unique_counter << " [color=blue]\n";
            std::cout << "MINUS_" << unique_counter << " -> " << value.second << "_" << unique_counter << " [color=blue]\n";
            std::cout << value.second << "_" << unique_counter << " [label = \"" << value.second << "\"]\n";
            std::cout << "MINUS_" << unique_counter-- << " [label = \"-\"]\n";
        } else {
            std::cout << "PLUS_" << unique_counter << " [color=red]\n";
            std::cout << "PLUS_" << unique_counter << " -> " << value.second << "_" << unique_counter << " [color=red]\n";
            std::cout << value.second << "_" << unique_counter << " [label = \"" << value.second << "\"]\n";
            std::cout << "PLUS_" << unique_counter-- << " [label = \"+\"]\n";
        }
    }
}
void AstPrintVisitor::printExpressions(std::vector<std::unique_ptr<Expression>>& expressions) {
    for (auto& expression : expressions) {
        std::cout << "PLUS_" << unique_counter << " [color=orange]\n";
        std::cout << "PLUS_" << unique_counter << " [label = \"+\"]\n";

        std::cout << "PLUS_" << unique_counter-- << " -> Expression_" << expression_counter << " [color=orange]\n";
        std::cout << "Expression_" << expression_counter << " -> ";
        std::size_t current_expression = expression_counter;
        expression_counter++;
        expression->accept(*this);
        if (expression != expressions.back()) {
            std::cout << "Expression_" << current_expression << " -> ";
        }
    }
}

} // namespace ast
