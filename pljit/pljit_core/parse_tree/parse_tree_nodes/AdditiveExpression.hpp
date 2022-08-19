#ifndef PLJIT_PARSETREE_ADDITIVEEXPRESSION_HPP
#define PLJIT_PARSETREE_ADDITIVEEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "../ParseTreeVisitor.hpp"
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
    AdditiveExpression(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    AdditiveExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    void accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
};

} // namespace parse_tree

#endif //PLJIT_PARSETREE_ADDITIVEEXPRESSION_HPP
