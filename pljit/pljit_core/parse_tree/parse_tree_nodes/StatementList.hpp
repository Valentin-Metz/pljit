#ifndef PLJIT_STATEMENTLIST_HPP
#define PLJIT_STATEMENTLIST_HPP

#include "../../lexer/Lexer.hpp"
#include "TerminalSymbol.hpp"
#include <vector>
namespace parse_tree {
class Statement;

class StatementList {
    public:
    const std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> statementList;
    StatementList(lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
};

} // namespace parse_tree

#endif //PLJIT_STATEMENTLIST_HPP
