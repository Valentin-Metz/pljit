#ifndef PLJIT_INITDECLARATOR_HPP
#define PLJIT_INITDECLARATOR_HPP

#include "Identifier.hpp"
#include "Literal.hpp"
#include "lexer/Lexer.hpp"
namespace parse_tree {

class InitDeclarator {
    public:
    const Identifier identifier;
    const TerminalSymbol assignment_symbol;
    const Literal literal;

    InitDeclarator(lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_INITDECLARATOR_HPP
