#ifndef PLJIT_COMPOUNDSTATEMENT_HPP
#define PLJIT_COMPOUNDSTATEMENT_HPP

#include "../../lexer/Lexer.hpp"
#include "StatementList.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

class CompoundStatement {
    public:
    const TerminalSymbol begin;
    const StatementList statementList;
    CompoundStatement(TerminalSymbol begin, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_COMPOUNDSTATEMENT_HPP
