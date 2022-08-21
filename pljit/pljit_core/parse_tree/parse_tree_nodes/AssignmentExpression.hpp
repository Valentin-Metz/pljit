#ifndef PLJIT_ASSIGNMENTEXPRESSION_HPP
#define PLJIT_ASSIGNMENTEXPRESSION_HPP

#include "AdditiveExpression.hpp"
#include "Identifier.hpp"
#include "lexer/Lexer.hpp"
namespace parse_tree {

class AssignmentExpression {
    public:
    const Identifier identifier;
    const TerminalSymbol assignmentToken;
    const AdditiveExpression additiveExpression;
    AssignmentExpression(Identifier identifier, lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_ASSIGNMENTEXPRESSION_HPP
