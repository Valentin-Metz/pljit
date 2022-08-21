#include "ParseTree.hpp"
#include "parse_tree/visitor/ParseTreePrintVisitor.hpp"

namespace parse_tree {

void ParseTree::print() {
    ParseTreePrintVisitor print_visitor;
    root.accept(print_visitor);
}
ParseTree::ParseTree(lexer::Lexer& l) : root(FunctionDefinition(l)) {}
ParseTree::~ParseTree() = default;

} // namespace parse_tree
