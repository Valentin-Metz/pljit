#include "Ast.hpp"
#include "AstPrintVisitor.hpp"
#include "AstVisitor.hpp"

namespace ast {

AST::AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) : symbolTable(parse_tree, source_code), function(std::make_unique<Function>(parse_tree.root.compound_statement.value().statementList, symbolTable, source_code)), sourceCode(source_code) {}

void AST::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

void AST::print() {
    AstPrintVisitor print_visitor;
    this->accept(print_visitor);
}
ExecutionTable AST::getExecutionTable() {
    if (executionTable) return executionTable.value();

    ExecutionTable t;
    for (auto& entry : symbolTable.table) {
        t.insert(entry.first, std::get<2>(entry.second));
    }

    executionTable.emplace(t);
    return executionTable.value();
}

} // namespace ast
