#include "Function.hpp"
#include "../../parse_tree/ParseTree.hpp"
#include "../../parse_tree/parse_tree_nodes/Statement.hpp"
#include "AssignmentStatement.hpp"
#include "ReturnStatement.hpp"

namespace ast {
Function::Function(const parse_tree::StatementList& statement_list, SymbolTable& symbol_table, source_code::SourceCode& source_code) {
    bool contains_return_statement = false;
    for (auto& statement : statement_list.statementList) {
        if (statement.first.get()->assignmentExpression) {
            statements.push_back(std::make_unique<AssignmentStatement>(statement.first.get()->assignmentExpression.value().get(), symbol_table, source_code));
        } else {
            statements.push_back(std::make_unique<ReturnStatement>(statement.first.get()->additiveExpression.value().second.get(), symbol_table, source_code));
            contains_return_statement = true;
        }
    }
    if (!contains_return_statement) {
        throw CompilationError(statement_list.statementList.back().second.source_code_reference, CompilationError::ErrorSource::AST, "Missing RETURN statement");
    }
}
Function::~Function() = default;
} // namespace ast
