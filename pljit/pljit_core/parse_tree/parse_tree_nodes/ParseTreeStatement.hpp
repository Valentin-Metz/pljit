#ifndef PLJIT_PARSETREESTATEMENT_HPP
#define PLJIT_PARSETREESTATEMENT_HPP

#include "../../lexer/Lexer.hpp"
#include "../ParseTreeVisitor.hpp"
#include <optional>
namespace parse_tree {

class TerminalSymbol;
class AssignmentExpression;

class ParseTreeStatement {
    public:
    std::optional<std::unique_ptr<const AssignmentExpression>> assignmentExpression;
    std::optional<std::pair<std::unique_ptr<const TerminalSymbol>, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    ~ParseTreeStatement();
    ParseTreeStatement(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREESTATEMENT_HPP
