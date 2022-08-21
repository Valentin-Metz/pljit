#ifndef PLJIT_PRIMARYEXPRESSION_HPP
#define PLJIT_PRIMARYEXPRESSION_HPP

#include "Identifier.hpp"
#include "Literal.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/Lexer.hpp"
#include "lexer/tokens/LexerToken.hpp"
#include <memory>
#include <optional>
namespace parse_tree {
class AdditiveExpression;

class PrimaryExpression {
    public:
    PrimaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l);
    ~PrimaryExpression();
    std::optional<Identifier> identifier;
    std::optional<Literal> literal;
    std::optional<TerminalSymbol> openBracket;
    std::optional<std::unique_ptr<AdditiveExpression>> additiveExpression;
    std::optional<TerminalSymbol> closingBracket;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PRIMARYEXPRESSION_HPP
