#ifndef PLJIT_PRIMARYEXPRESSION_HPP
#define PLJIT_PRIMARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include "Identifier.hpp"
#include "Literal.hpp"
#include "TerminalSymbol.hpp"
#include <memory>
#include <optional>
namespace parse_tree {
class AdditiveExpression;

class PrimaryExpression {
    public:
    ~PrimaryExpression();
    std::optional<Identifier> identifier;
    std::optional<Literal> literal;
    std::optional<TerminalSymbol> openBracket;
    std::optional<std::unique_ptr<AdditiveExpression>> additiveExpression;
    std::optional<TerminalSymbol> closingBracket;
    PrimaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l);
    void accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }
};

} // namespace parse_tree

#endif //PLJIT_PRIMARYEXPRESSION_HPP
