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
    const TerminalSymbol end;
    CompoundStatement(TerminalSymbol begin, lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_COMPOUNDSTATEMENT_HPP
