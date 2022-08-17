#ifndef PLJIT_UNARYEXPRESSION_HPP
#define PLJIT_UNARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include <optional>
namespace parse_tree {

enum AdditiveOperator : int;

class UnaryExpression {
    public:
    std::optional<const AdditiveOperator> modifier;
    UnaryExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
    UnaryExpression(lexer::LexerToken lexer_token, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_UNARYEXPRESSION_HPP
