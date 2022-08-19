#include "Statement.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"
#include "Expression.hpp"

namespace ast {
Statement::~Statement() {
}
Statement::Statement(Statement::StatementType statement_type) : statementType(statement_type) {
}
void Statement::parseAdditiveExpression() {

}
} // namespace ast