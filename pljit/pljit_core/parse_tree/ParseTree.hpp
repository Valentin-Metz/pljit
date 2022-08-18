#ifndef PLJIT_PARSETREE_HPP
#define PLJIT_PARSETREE_HPP

#include "../lexer/Lexer.hpp"
#include "parse_tree_nodes/FunctionDefinition.hpp"
namespace parse_tree {

class ParseTree {
    public:
    ~ParseTree();
    const FunctionDefinition root;
    ParseTree(lexer::Lexer& l);
    void print();
};

} // namespace parse_tree

#endif //PLJIT_PARSETREE_HPP
