#ifndef PLJIT_STATEMENTLIST_HPP
#define PLJIT_STATEMENTLIST_HPP

#include "../../lexer/Lexer.hpp"
namespace parse_tree {

class StatementList {
    public:
    StatementList(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_STATEMENTLIST_HPP
