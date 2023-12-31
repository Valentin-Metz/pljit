#ifndef PLJIT_TERMINALEXPRESSION_HPP
#define PLJIT_TERMINALEXPRESSION_HPP

#include "Expression.hpp"
#include <cstdint>
#include <string_view>
#include <variant>
namespace ast {

/// A terminal expression contains either a literal or variable
class TerminalExpression : public Expression {
    public:
    /// Literal or signed identifier
    std::variant<int64_t, std::pair<int64_t, std::string_view>> value;

    TerminalExpression(std::variant<int64_t, std::pair<int64_t, std::string_view>> value);
    virtual void accept(AstVisitor& visitor) override;
    virtual int64_t execute(ExecutionTable& table) override;
};

} // namespace ast

#endif //PLJIT_TERMINALEXPRESSION_HPP
