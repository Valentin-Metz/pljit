#ifndef PLJIT_DECLARATORLIST_HPP
#define PLJIT_DECLARATORLIST_HPP

#include "Identifier.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/ParseTreeVisitor.hpp"
#include <vector>
namespace parse_tree {

class DeclaratorList {
    public:
    const std::vector<std::pair<const Identifier, const TerminalSymbol>> declaratorList;
    DeclaratorList(lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_DECLARATORLIST_HPP
