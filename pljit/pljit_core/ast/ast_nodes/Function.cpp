#include "Function.hpp"
#include "../../parse_tree/ParseTree.hpp"
#include "../../parse_tree/parse_tree_nodes/StatementList.hpp"
//#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "Statement.hpp"

namespace ast {
Function::Function(const parse_tree::StatementList& statement_list, source_code::SourceCode& source_code) {
    for (auto& statement : statement_list.statementList) {
        //if (statement.first.get().)
    }
}
Function::~Function() = default;
} // namespace ast
