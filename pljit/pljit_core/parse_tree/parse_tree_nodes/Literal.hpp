#ifndef PLJIT_LITERAL_HPP
#define PLJIT_LITERAL_HPP

#include "TerminalSymbol.hpp"
#include <cstdint>
namespace parse_tree {

class Literal {
    public:
    const TerminalSymbol literal;
    const std::int64_t value;
    Literal(TerminalSymbol literal, std::int64_t value) : literal(literal), value(value) {}
};

} // namespace parse_tree

#endif //PLJIT_LITERAL_HPP
