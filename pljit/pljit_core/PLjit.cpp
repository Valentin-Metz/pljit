#include "PLjit.hpp"
#include "FunctionHandle.hpp"
#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"

namespace pljit {

PLjit::PLjit() = default;
PLjit::~PLjit() = default;

FunctionHandle PLjit::registerFunction(std::string source_code) {
    return functionStorage->registerFunction(std::move(source_code));
}

} // namespace pljit
