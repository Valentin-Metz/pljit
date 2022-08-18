#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include "AdditiveExpression.hpp"
#include "AssignmentExpression.hpp"
#include "TerminalSymbol.hpp"
#include <optional>
namespace parse_tree {

class Statement {
    public:
    std::optional<const AssignmentExpression> assignmentExpression;
    std::optional<std::pair<const TerminalSymbol, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    Statement(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
};

} // namespace parse_tree

#endif //PLJIT_STATEMENT_HPP
