#ifndef PLJIT_PARSETREE_HPP
#define PLJIT_PARSETREE_HPP

#include "../lexer/Lexer.hpp"
#include "parse_tree_nodes/FunctionDefinition.hpp"
#include "ParseTreePrintVisitor.hpp"
namespace parse_tree {

class ParseTree {
    public:
    const FunctionDefinition root;
    ParseTree(lexer::Lexer& l) : root(FunctionDefinition(l)) {}
    void print();
};

} // namespace parse_tree

#endif //PLJIT_PARSETREE_HPP
