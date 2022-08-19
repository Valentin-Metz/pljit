#include "TerminalExpression.hpp"
#include "../AstVisitor.hpp"

namespace ast {

TerminalExpression::TerminalExpression(std::variant<int64_t, std::pair<int64_t, std::string_view>> value) : Expression(Terminal), value(value) {}

void TerminalExpression::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}
int64_t TerminalExpression::execute(ExecutionTable& table) {
    return 0;
}

} // namespace ast
