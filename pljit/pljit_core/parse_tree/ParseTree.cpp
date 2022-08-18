#include "ParseTree.hpp"
#include "ParseTreePrintVisitor.hpp"

namespace parse_tree {

void ParseTree::print() {
    ParseTreePrintVisitor print_visitor;
    root.accept(print_visitor);
}
ParseTree::ParseTree(lexer::Lexer& l) : root(FunctionDefinition(l)) {}

} // namespace parse_tree
