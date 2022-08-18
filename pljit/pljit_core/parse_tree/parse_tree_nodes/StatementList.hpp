#ifndef PLJIT_STATEMENTLIST_HPP
#define PLJIT_STATEMENTLIST_HPP

#include "../../lexer/Lexer.hpp"
#include "TerminalSymbol.hpp"
#include <vector>
namespace parse_tree {
class ParseTreeStatement;

class StatementList {
    public:
    std::vector<std::pair<std::unique_ptr<const ParseTreeStatement>, const TerminalSymbol>> statementList;
    StatementList(lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
};

} // namespace parse_tree

#endif //PLJIT_STATEMENTLIST_HPP
