#ifndef PLJIT_PRIMARYEXPRESSION_HPP
#define PLJIT_PRIMARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include "TerminalSymbol.hpp"
#include <memory>
#include <optional>
namespace parse_tree {
class AdditiveExpression;

class PrimaryExpression {
    public:
    ~PrimaryExpression();
    std::optional<TerminalSymbol> identifier;
    std::optional<std::pair<TerminalSymbol, std::int64_t>> literal;
    std::optional<TerminalSymbol> openBracket;
    std::optional<std::unique_ptr<AdditiveExpression>> additiveExpression;
    std::optional<TerminalSymbol> closingBracket;
    PrimaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_PRIMARYEXPRESSION_HPP
