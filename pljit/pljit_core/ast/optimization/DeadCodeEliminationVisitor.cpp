#include "DeadCodeEliminationVisitor.hpp"
#include "ast/Ast.hpp"

namespace ast {

void DeadCodeEliminationVisitor::visit(AST& node) {
    node.function->accept(*this);
}

void DeadCodeEliminationVisitor::visit(Function& node) {
    std::size_t counter = 0;
    for (auto& statement : node.statements) {
        counter++;
        if (statement->statementType == Statement::Return) break;
    }
    node.statements.resize(counter);
}

void DeadCodeEliminationVisitor::visit(SymbolTable& node) {}
void DeadCodeEliminationVisitor::visit(AssignmentStatement& node) {}
void DeadCodeEliminationVisitor::visit(ReturnStatement& node) {}
void DeadCodeEliminationVisitor::visit(MultiplicativeExpression& node) {}
void DeadCodeEliminationVisitor::visit(TerminalExpression& node) {}

} // namespace ast
