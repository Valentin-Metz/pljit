#ifndef PLJIT_STATEMENT_HPP
#define PLJIT_STATEMENT_HPP

#include "../../lexer/Lexer.hpp"
#include "AdditiveExpression.hpp"
#include "AssignmentExpression.hpp"
#include "TerminalSymbol.hpp"
#include <optional>
namespace parse_tree {

class Statement {
    public:
    std::optional<const AssignmentExpression> assignmentExpression;
    std::optional<std::pair<const TerminalSymbol, const AdditiveExpression>> additiveExpression;
    Statement(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_STATEMENT_HPP
