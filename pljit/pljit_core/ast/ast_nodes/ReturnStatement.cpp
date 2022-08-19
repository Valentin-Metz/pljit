#include "ReturnStatement.hpp"
#include "../../parse_tree/parse_tree_nodes/Statement.hpp"
#include "../AstVisitor.hpp"

namespace ast {
ReturnStatement::ReturnStatement(const parse_tree::AdditiveExpression* return_statement, SymbolTable& symbol_table, source_code::SourceCode& source_code) : Statement(Return) {}

void ReturnStatement::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

} // namespace ast
