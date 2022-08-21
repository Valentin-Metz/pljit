#ifndef PLJIT_UNARYEXPRESSION_HPP
#define PLJIT_UNARYEXPRESSION_HPP

#include "ArithmeticSymbol.hpp"
#include "PrimaryExpression.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/Visitor/ParseTreeVisitor.hpp"
#include <optional>
namespace parse_tree {

class UnaryExpression {
    public:
    UnaryExpression(lexer::Lexer& l);
    UnaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l);
    std::optional<std::pair<const TerminalSymbol, const ArithmeticSymbol>> modifier;
    std::optional<std::unique_ptr<const PrimaryExpression>> primaryExpression;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_UNARYEXPRESSION_HPP
