#ifndef PLJIT_UNARYEXPRESSION_HPP
#define PLJIT_UNARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include <optional>
namespace parse_tree {

class UnaryExpression {
    public:
    UnaryExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_UNARYEXPRESSION_HPP
