#ifndef PLJIT_MULTIPLICATIVEEXPRESSION_HPP
#define PLJIT_MULTIPLICATIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include <memory>
#include <optional>
namespace parse_tree {

class MultiplicativeExpression {
    public:
    enum MultiplicativeOperator {
        MULTIPLY,
        DIVIDE,
    };
    const std::pair<TerminalSymbol, MultiplicativeOperator> multiplicativeOperator;
    const UnaryExpression unaryExpression;
    MultiplicativeExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_MULTIPLICATIVEEXPRESSION_HPP
