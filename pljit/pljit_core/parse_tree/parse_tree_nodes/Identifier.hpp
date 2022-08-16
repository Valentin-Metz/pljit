#ifndef PLJIT_IDENTIFIER_HPP
#define PLJIT_IDENTIFIER_HPP

#include "TerminalSymbol.hpp"
namespace parse_tree {

class Identifier {
    public:
    const TerminalSymbol identifier;
    Identifier(TerminalSymbol identifier) : identifier(identifier) {}
};

} // namespace parse_tree

#endif //PLJIT_IDENTIFIER_HPP
