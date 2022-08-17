#ifndef PLJIT_STATEMENTLIST_HPP
#define PLJIT_STATEMENTLIST_HPP

#include "../../lexer/Lexer.hpp"
#include "Statement.hpp"
#include "TerminalSymbol.hpp"
#include <vector>
namespace parse_tree {

class StatementList {
    public:
    const std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> statementList;
    StatementList(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_STATEMENTLIST_HPP
