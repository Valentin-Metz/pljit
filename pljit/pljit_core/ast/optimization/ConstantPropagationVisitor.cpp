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

static bool is_expression_const(std::unique_ptr<Expression>& e) {
    return e->expressionType == Expression::Terminal && static_cast<TerminalExpression&>(*e.get()).value.index() == 0;
}

static void optimize_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ConstantPropagationVisitor& visitor) {
    for (std::size_t i = 0; i < expressions.size(); ++i) {
        expressions[i]->accept(visitor);
        if (expressions[i].get()->expressionType == Expression::Terminal) {
            if (i > 0 && is_expression_const(expressions[i - 1]) && is_expression_const(expressions[i])) {
                auto& previousExpression = static_cast<TerminalExpression&>(*expressions[i - 1].get());
                auto& currentExpression = static_cast<TerminalExpression&>(*expressions[i].get());

                previousExpression.value = std::get<0>(previousExpression.value) + std::get<0>(currentExpression.value);
                expressions.erase(expressions.begin() + i);
                --i;
            }
        } else {
            auto& containedExpressions = static_cast<MultiplicativeExpression&>(*expressions[i]).expressions;
            if (i > 0 && containedExpressions.size() == 1 && is_expression_const(expressions[i - 1]) && is_expression_const(containedExpressions[0])) {
                auto& previousExpression = static_cast<TerminalExpression&>(*expressions[i - 1].get());
                auto& currentExpression = static_cast<TerminalExpression&>(*containedExpressions[0].get());

                previousExpression.value = std::get<0>(previousExpression.value) * std::get<0>(currentExpression.value);
                expressions.erase(expressions.begin() + i);
                --i;
            }
        }
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
