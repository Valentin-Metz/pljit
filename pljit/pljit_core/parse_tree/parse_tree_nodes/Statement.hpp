#ifndef PLJIT_PARSETREE_STATEMENT_HPP
#define PLJIT_PARSETREE_STATEMENT_HPP

#include "lexer/Lexer.hpp"
#include "parse_tree/ParseTreeVisitor.hpp"
#include <optional>
namespace parse_tree {

class TerminalSymbol;
class AssignmentExpression;

class Statement {
    public:
    Statement(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator);
    ~Statement();
    std::optional<std::unique_ptr<const AssignmentExpression>> assignmentExpression;
    std::optional<std::pair<std::unique_ptr<const TerminalSymbol>, std::unique_ptr<const AdditiveExpression>>> additiveExpression;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_PARSETREE_STATEMENT_HPP
