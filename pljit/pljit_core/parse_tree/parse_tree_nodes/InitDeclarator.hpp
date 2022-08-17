#ifndef PLJIT_INITDECLARATOR_HPP
#define PLJIT_INITDECLARATOR_HPP

#include "../../lexer/Lexer.hpp"
#include "Identifier.hpp"
#include "Literal.hpp"
namespace parse_tree {

class InitDeclarator {
    public:
    const Identifier identifier;
    const TerminalSymbol assignment_symbol;
    const Literal literal;

    InitDeclarator(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_INITDECLARATOR_HPP
