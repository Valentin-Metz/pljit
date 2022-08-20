#include "ConstantPropagationVisitor.hpp"
#include "ast/Ast.hpp"
#include "ast/ast_nodes/AssignmentStatement.hpp"
#include "ast/ast_nodes/Expression.hpp"
#include "ast/ast_nodes/MultiplicativeExpression.hpp"
#include "ast/ast_nodes/ReturnStatement.hpp"
#include "ast/ast_nodes/TerminalExpression.hpp"

namespace ast {

void ConstantPropagationVisitor::visit(AST& node) {
    node.symbolTable.accept(*this);
    node.function->accept(*this);
}

void ConstantPropagationVisitor::visit(SymbolTable& node) {
    for (auto& entry : node.table) {
        if (std::get<0>(entry.second) == SymbolTable::Constant) {
            constant_identifiers.insert(std::make_pair(entry.first, std::get<2>(entry.second)));
        }
    }
}

void ConstantPropagationVisitor::visit(Function& node) {
    auto& statements = node.statements;
    for (std::size_t i = 0; i < statements.size(); ++i) {
        statements[i]->accept(*this);
        if (statements[i]->statementType == Statement::Assignment && statements[i]->expressions.empty()) {
            statements.erase(statements.begin() + i);
            --i;
        }
    }
}

static void optimize_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ConstantPropagationVisitor& visitor) {
    for (std::size_t i = 0; i < expressions.size(); ++i) {
        expressions[i]->accept(visitor);
    }
}

void ConstantPropagationVisitor::visit(AssignmentStatement& node) {
    optimize_expressions(node.expressions, *this);
    auto& expressions = node.expressions;
    if (expressions.size() == 1 && static_cast<TerminalExpression&>(*expressions[0].get()).value.index() == 0) {
        constant_identifiers.insert(std::make_pair(node.target, std::get<0>(static_cast<TerminalExpression&>(*expressions[0].get()).value)));
        expressions.clear();
    }
}

void ConstantPropagationVisitor::visit(ReturnStatement& node) {
    optimize_expressions(node.expressions, *this);
}

void ConstantPropagationVisitor::visit(MultiplicativeExpression& node) {
    optimize_expressions(node.expressions, *this);
}

void ConstantPropagationVisitor::visit(TerminalExpression& node) {
    if (node.value.index() == 1 && constant_identifiers.find(std::get<1>(node.value).second) != constant_identifiers.end()) {
        node.value = constant_identifiers.find(std::get<1>(node.value).second)->second * std::get<1>(node.value).first;
    }
}

} // namespace ast
