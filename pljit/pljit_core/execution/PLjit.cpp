#include "include/PLjit.hpp"
#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit_FunctionHandle.hpp"

namespace pljit {

PLjit::PLjit() {
    functionStorage = std::make_unique<FunctionStorage>();
}

PLjit::~PLjit() = default;

PLjit_FunctionHandle PLjit::registerFunction(std::string_view source_code) {
    return functionStorage->registerFunction(std::move(source_code));
}

} // namespace pljit
