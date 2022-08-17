#ifndef PLJIT_ADDITIVEEXPRESSION_HPP
#define PLJIT_ADDITIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "MultiplicativeExpression.hpp"
#include "TerminalSymbol.hpp"
#include "UnaryExpression.hpp"
#include <optional>
#include <vector>
#include <memory>
namespace parse_tree {

class AdditiveExpression {
    public:
    MultiplicativeExpression multiplicativeExpression;
    std::optional<std::pair<TerminalSymbol, std::unique_ptr<AdditiveExpression>>> additiveExpression;
    AdditiveExpression(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_ADDITIVEEXPRESSION_HPP
