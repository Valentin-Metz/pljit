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

void DeadCodeEliminationVisitor::visit(SymbolTable&) {}
void DeadCodeEliminationVisitor::visit(AssignmentStatement&) {}
void DeadCodeEliminationVisitor::visit(ReturnStatement&) {}
void DeadCodeEliminationVisitor::visit(MultiplicativeExpression&) {}
void DeadCodeEliminationVisitor::visit(TerminalExpression&) {}

} // namespace ast
