#include "Statement.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "Expression.hpp"

namespace ast {
Statement::~Statement() {
}
//todo
Statement::Statement(Statement::StatementType statement_type, parse_tree::ParseTreeStatement statement) : statementType(Assignment) {
}
} // namespace ast