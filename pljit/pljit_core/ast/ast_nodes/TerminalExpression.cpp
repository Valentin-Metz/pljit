#include "TerminalExpression.hpp"
#include "ast/ast_core/AstVisitor.hpp"
#include "ast/ast_core/ExecutionTable.hpp"

namespace ast {

TerminalExpression::TerminalExpression(std::variant<int64_t, std::pair<int64_t, std::string_view>> value) : Expression(Terminal), value(value) {}

void TerminalExpression::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

int64_t TerminalExpression::execute(ExecutionTable& table) {
    if (value.index() == 0) {
        return std::get<0>(value);
    } else {
        return std::get<1>(value).first * table.get(std::get<1>(value).second);
    }
}

} // namespace ast
