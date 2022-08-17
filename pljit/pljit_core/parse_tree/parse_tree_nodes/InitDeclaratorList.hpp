#ifndef PLJIT_INITDECLARATORLIST_HPP
#define PLJIT_INITDECLARATORLIST_HPP

#include "../../lexer/Lexer.hpp"
#include "InitDeclarator.hpp"
#include "Literal.hpp"
#include "TerminalSymbol.hpp"
#include <vector>
namespace parse_tree {

class InitDeclaratorList {
    public:
    const std::vector<std::pair<const InitDeclarator, const TerminalSymbol>> initDeclaratorList;
    InitDeclaratorList(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_INITDECLARATORLIST_HPP
