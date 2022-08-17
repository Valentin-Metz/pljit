#ifndef PLJIT_PRIMARYEXPRESSION_HPP
#define PLJIT_PRIMARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include <optional>
namespace parse_tree {

class PrimaryExpression {
    PrimaryExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_PRIMARYEXPRESSION_HPP
