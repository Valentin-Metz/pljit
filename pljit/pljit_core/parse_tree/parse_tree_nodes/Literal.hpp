#ifndef PLJIT_LITERAL_HPP
#define PLJIT_LITERAL_HPP

#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/visitor/ParseTreeVisitor.hpp"
#include <cstdint>
namespace parse_tree {

class Literal {
    public:
    const std::pair<const TerminalSymbol, const std::int64_t> literal;
    Literal(lexer::Lexer& l);
    Literal(std::pair<TerminalSymbol, std::int64_t> literal);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_LITERAL_HPP
