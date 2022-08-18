#ifndef PLJIT_AST_HPP
#define PLJIT_AST_HPP

#include "../parse_tree/ParseTree.hpp"
#include "SymbolTable.hpp"
#include "ast_nodes/Function.hpp"

namespace ast {

class AST {
    SymbolTable symbolTable;
    Function function;

    public:
    AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
};

} // namespace ast

#endif //PLJIT_AST_HPP
