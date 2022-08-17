#ifndef PLJIT_ADDITIVEEXPRESSION_HPP
#define PLJIT_ADDITIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "MultiplicativeExpression.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include <memory>
#include <optional>
#include <vector>
namespace parse_tree {

class AdditiveExpression {
    public:
    enum AdditiveOperator {
        PLUS,
        MINUS,
    };
    UnaryExpression unaryExpression;
    //std::vector<MultiplicativeExpression> multiplicativeExpression;
    //std::optional<std::pair<std::pair<const TerminalSymbol, const AdditiveOperator>, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    AdditiveExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_ADDITIVEEXPRESSION_HPP
