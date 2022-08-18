#include "Function.hpp"
//#include "../../parse_tree/ParseTree.hpp"
#include "../../parse_tree/parse_tree_nodes/TerminalSymbol.hpp"
#include "Statement.hpp"

namespace ast {
Function::Function(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) {
    //for (const std::pair<std::unique_ptr<const Statement>, const parse_tree::TerminalSymbol> statement : parse_tree.root.compound_statement.value().statementList.statementList) {
    //}
}
Function::~Function() = default;
} // namespace ast
