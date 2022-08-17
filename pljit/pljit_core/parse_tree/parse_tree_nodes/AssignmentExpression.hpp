#ifndef PLJIT_ASSIGNMENTEXPRESSION_HPP
#define PLJIT_ASSIGNMENTEXPRESSION_HPP

#include "../../lexer/Lexer.hpp"
#include "AdditiveExpression.hpp"
#include "Identifier.hpp"
namespace parse_tree {

class AssignmentExpression {
    public:
    const Identifier identifier;
    const TerminalSymbol assignmentToken;
    const AdditiveExpression additiveExpression;
    AssignmentExpression(Identifier identifier, lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_ASSIGNMENTEXPRESSION_HPP
