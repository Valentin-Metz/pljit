#ifndef PLJIT_INITDECLARATORLIST_HPP
#define PLJIT_INITDECLARATORLIST_HPP

#include "Literal.hpp"
#include "TerminalSymbol.hpp"
#include <tuple>
#include <vector>
namespace parse_tree {

class InitDeclaratorList {
    public:
    const TerminalSymbol keyword;
    std::vector<std::tuple<Literal, TerminalSymbol>> declarator_list;
};

} // namespace parse_tree

#endif //PLJIT_INITDECLARATORLIST_HPP
