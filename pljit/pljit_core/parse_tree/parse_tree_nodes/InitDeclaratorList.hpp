#ifndef PLJIT_INITDECLARATORLIST_HPP
#define PLJIT_INITDECLARATORLIST_HPP

#include "InitDeclarator.hpp"
#include "Literal.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include <vector>
namespace parse_tree {

class InitDeclaratorList {
    public:
    const std::vector<std::pair<const InitDeclarator, const TerminalSymbol>> initDeclaratorList;
    InitDeclaratorList(lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_INITDECLARATORLIST_HPP
