#ifndef PLJIT_LITERAL_HPP
#define PLJIT_LITERAL_HPP

#include "../../lexer/Lexer.hpp"
#include "../ParseTreeVisitor.hpp"
#include "TerminalSymbol.hpp"
#include <cstdint>
namespace parse_tree {

class Literal {
    public:
    const std::pair<const TerminalSymbol, const std::int64_t> literal;
    Literal(lexer::Lexer& l);
    Literal(std::pair<TerminalSymbol, std::int64_t> literal);
    void accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
};

} // namespace parse_tree

#endif //PLJIT_LITERAL_HPP
