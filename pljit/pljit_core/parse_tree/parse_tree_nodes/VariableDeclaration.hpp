#ifndef PLJIT_VARIABLEDECLARATION_HPP
#define PLJIT_VARIABLEDECLARATION_HPP

#include "DeclaratorList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class VariableDeclaration {
    public:
    VariableDeclaration(TerminalSymbol keyword, lexer::Lexer& l);
    const TerminalSymbol keyword;
    const DeclaratorList declaratorList;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_VARIABLEDECLARATION_HPP
