#ifndef PLJIT_VARIABLEDECLARATION_HPP
#define PLJIT_VARIABLEDECLARATION_HPP

#include "DeclaratorList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class VariableDeclaration {
    public:
    const TerminalSymbol keyword;
    const DeclaratorList declaratorList;
    VariableDeclaration(TerminalSymbol keyword, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_VARIABLEDECLARATION_HPP
