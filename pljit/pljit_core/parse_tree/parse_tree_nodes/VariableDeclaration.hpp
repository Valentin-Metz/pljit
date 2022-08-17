#ifndef PLJIT_VARIABLEDECLARATION_HPP
#define PLJIT_VARIABLEDECLARATION_HPP

#include "DeclaratorList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class VariableDeclaration {
    public:
    const TerminalSymbol keyword;
    const DeclaratorList declaratorList;
    VariableDeclaration(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword), declaratorList(DeclaratorList(l)) {}
};

} // namespace parse_tree

#endif //PLJIT_VARIABLEDECLARATION_HPP
