#ifndef PLJIT_CONSTANTDECLARATION_HPP
#define PLJIT_CONSTANTDECLARATION_HPP

#include "../../lexer/Lexer.hpp"
#include "InitDeclaratorList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class ConstantDeclaration {
    public:
    const TerminalSymbol keyword;
    const InitDeclaratorList initDeclaratorList;
    ConstantDeclaration(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword), initDeclaratorList(l) {}
};

} // namespace parse_tree

#endif //PLJIT_CONSTANTDECLARATION_HPP
