#include "AdditiveExpression.hpp"
#include "../AstVisitor.hpp"

namespace ast {

void AdditiveExpression::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

} // namespace ast
