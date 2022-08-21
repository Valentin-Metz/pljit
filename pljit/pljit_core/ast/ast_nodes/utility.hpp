#ifndef PLJIT_UTILITY_HPP
#define PLJIT_UTILITY_HPP

#include "Expression.hpp"
#include <cstdint>
#include <memory>
#include <vector>
namespace ast {

/// Evaluates a list of expressions and returns their result
std::int64_t evaluate_expressions(std::vector<std::unique_ptr<Expression>>& expressions, ExecutionTable& table);

} // namespace ast

#endif //PLJIT_UTILITY_HPP
