#ifndef PLJIT_ADDITIVEEXPRESSION_HPP
#define PLJIT_ADDITIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "ArithmeticSymbol.hpp"
#include "MultiplicativeExpression.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include <memory>
#include <optional>
#include <vector>
namespace parse_tree {

class AdditiveExpression {
    public:
    UnaryExpression unaryExpression;
    std::vector<std::unique_ptr<MultiplicativeExpression>> multiplicativeExpression;
    std::optional<std::pair<std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>>, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    AdditiveExpression(lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
    AdditiveExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_ADDITIVEEXPRESSION_HPP
