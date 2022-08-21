#ifndef PLJIT_STATEMENTLIST_HPP
#define PLJIT_STATEMENTLIST_HPP

#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include <vector>
namespace parse_tree {
class Statement;

class StatementList {
    public:
    StatementList(lexer::Lexer& l);
    std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> statementList;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_STATEMENTLIST_HPP
