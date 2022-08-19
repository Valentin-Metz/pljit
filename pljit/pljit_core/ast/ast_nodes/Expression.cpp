#include "Expression.hpp"

namespace ast {

Expression::~Expression() = default;

Expression::Expression(const ExpressionType expression_type) : expressionType(expression_type) {}
} // namespace ast
