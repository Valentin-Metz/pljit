#include "Ast.hpp"
#include "ast_core/AstVisitor.hpp"
#include "ast_core/ExecutionTable.hpp"
#include "optimization/AstOptimizationVisitor.hpp"
#include "print/AstPrintVisitor.hpp"

namespace ast {

AST::AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode source_code) : symbolTable(parse_tree, source_code), function(std::make_unique<Function>(parse_tree.root.compound_statement.value().statementList, symbolTable, source_code)), sourceCode(std::move(source_code)) {}
AST::~AST() = default;

void AST::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

void AST::print() {
    AstPrintVisitor print_visitor;
    this->accept(print_visitor);
}

void AST::optimize() {
    AstOptimizationVisitor optimization_visitor;
    this->accept(optimization_visitor);
}

void AST::generateExecutionTable() {
    ExecutionTable t(symbolTable.parameters);
    for (auto& entry : symbolTable.table) {
        t.insert(entry.first, std::get<2>(entry.second));
    }
    executionTable.emplace(t);
}

ExecutionTable AST::getExecutionTable() {
    return executionTable.value();
}

} // namespace ast
