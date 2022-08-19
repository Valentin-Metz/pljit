#ifndef PLJIT_PARAMETERDECLARATION_HPP
#define PLJIT_PARAMETERDECLARATION_HPP

#include "DeclaratorList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class ParameterDeclaration {
    public:
    const TerminalSymbol keyword;
    const DeclaratorList declaratorList;
    ParameterDeclaration(TerminalSymbol keyword, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PARAMETERDECLARATION_HPP
