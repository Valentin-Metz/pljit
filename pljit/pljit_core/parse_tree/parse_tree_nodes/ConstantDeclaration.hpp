#ifndef PLJIT_CONSTANTDECLARATION_HPP
#define PLJIT_CONSTANTDECLARATION_HPP

#include "InitDeclaratorList.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
namespace parse_tree {

class ConstantDeclaration {
    public:
    const TerminalSymbol keyword;
    const InitDeclaratorList initDeclaratorList;
    ConstantDeclaration(TerminalSymbol keyword, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_CONSTANTDECLARATION_HPP
