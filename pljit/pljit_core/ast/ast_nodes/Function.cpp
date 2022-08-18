#include "Function.hpp"
#include "../../parse_tree/ParseTree.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "AssignmentStatement.hpp"
#include "ReturnStatement.hpp"

namespace ast {
Function::Function(const parse_tree::StatementList& statement_list, SymbolTable& symbol_table, source_code::SourceCode& source_code) {
    for (auto& statement : statement_list.statementList) {
        if (statement.first.get()->assignmentExpression) {
            statements.push_back(std::make_unique<AssignmentStatement>(statement.first.get()->assignmentExpression.value().get(), symbol_table, source_code));
        } else {
            statements.push_back(std::make_unique<ReturnStatement>(statement.first.get()->additiveExpression.value().second.get(), symbol_table, source_code));
        }
    }
}
Function::~Function() = default;
} // namespace ast
