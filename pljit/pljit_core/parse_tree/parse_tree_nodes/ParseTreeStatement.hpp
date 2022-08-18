#ifndef PLJIT_PARSETREESTATEMENT_HPP
#define PLJIT_PARSETREESTATEMENT_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerToken.hpp"
#include "../ParseTreeVisitor.hpp"
#include "AdditiveExpression.hpp"
#include "AssignmentExpression.hpp"
#include <optional>
namespace parse_tree {

class TerminalSymbol;

class ParseTreeStatement {
    public:
    std::optional<const AssignmentExpression> assignmentExpression;
    std::optional<std::pair<const TerminalSymbol, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    ~ParseTreeStatement();
    ParseTreeStatement(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREESTATEMENT_HPP
