#ifndef PLJIT_LITERAL_HPP
#define PLJIT_LITERAL_HPP

#include "../../lexer/Lexer.hpp"
#include "TerminalSymbol.hpp"
#include <cstdint>
namespace parse_tree {

class Literal {
    public:
    const std::pair<const TerminalSymbol, const std::int64_t> literal;
    Literal(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_LITERAL_HPP
