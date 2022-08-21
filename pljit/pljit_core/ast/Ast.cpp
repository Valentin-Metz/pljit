#include "Ast.hpp"
#include "ast/optimization/ConstantPropagationOptimizationPass.hpp"
#include "ast/optimization/DeadCodeEliminationOptimizationPass.hpp"
#include "ast_core/AstVisitor.hpp"
#include "ast_core/ExecutionTable.hpp"
#include "print/AstPrintVisitor.hpp"

namespace ast {

AST::AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) : symbolTable(parse_tree, source_code), function(std::make_unique<Function>(parse_tree.root.compound_statement.value().statementList, symbolTable, source_code)), sourceCode(std::move(source_code)) {}
AST::~AST() = default;

void AST::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

void AST::print() {
    AstPrintVisitor print_visitor;
    this->accept(print_visitor);
}

void AST::optimize() {
    DeadCodeEliminationOptimizationPass dead_code_elimination_optimization_pass;
    dead_code_elimination_optimization_pass.optimize(*this);

    ConstantPropagationOptimizationPass constant_propagation_optimization_pass;
    constant_propagation_optimization_pass.optimize(*this);
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
