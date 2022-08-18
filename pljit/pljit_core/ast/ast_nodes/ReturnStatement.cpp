#include "ReturnStatement.hpp"
#include "../../parse_tree/parse_tree_nodes/ParseTreeStatement.hpp"

namespace ast {
ReturnStatement::ReturnStatement(const parse_tree::AdditiveExpression* statement) : Statement(Return) {}
} // namespace ast