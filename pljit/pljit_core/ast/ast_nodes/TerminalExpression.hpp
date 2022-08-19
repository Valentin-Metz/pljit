#ifndef PLJIT_TERMINALEXPRESSION_HPP
#define PLJIT_TERMINALEXPRESSION_HPP

#include "Expression.hpp"
#include <cstdint>
#include <string_view>
#include <variant>
namespace ast {

class TerminalExpression : public Expression {
    /// Literal or signed identifier
    const std::variant<int64_t, std::pair<int64_t, std::string_view>> value;

    public:
    TerminalExpression(std::variant<int64_t, std::pair<int64_t, std::string_view>> value);
    virtual void accept(AstVisitor& visitor) override;
};

} // namespace ast

#endif //PLJIT_TERMINALEXPRESSION_HPP
