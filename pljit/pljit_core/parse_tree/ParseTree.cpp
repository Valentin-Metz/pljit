#include "ParseTree.hpp"

namespace parse_tree {

void ParseTree::print() {
    ParseTreePrintVisitor print_visitor;
    root.accept(print_visitor);
}

} // namespace parse_tree
