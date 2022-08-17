#ifndef PLJIT_DECLARATORLIST_HPP
#define PLJIT_DECLARATORLIST_HPP

#include "../../lexer/Lexer.hpp"

#include "Identifier.hpp"
#include "TerminalSymbol.hpp"
#include <vector>
namespace parse_tree {

class DeclaratorList {
    public:
    std::vector<std::pair<Identifier, TerminalSymbol>> declarator_list;
    DeclaratorList(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_DECLARATORLIST_HPP
