#ifndef PLJIT_PRIMARYEXPRESSION_HPP
#define PLJIT_PRIMARYEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include "TerminalSymbol.hpp"
#include <memory>
#include <optional>
namespace parse_tree {

class PrimaryExpression {
    public:
    std::optional<TerminalSymbol> identifier;
    std::optional<TerminalSymbol> literal;
    std::optional<TerminalSymbol> openBracket;
    std::optional<std::unique_ptr<PrimaryExpression>> primaryExpression;
    std::optional<TerminalSymbol> closingBracket;
    PrimaryExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator);
};

} // namespace parse_tree

#endif //PLJIT_PRIMARYEXPRESSION_HPP
