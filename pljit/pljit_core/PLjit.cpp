#include "PLjit.hpp"
#include "FunctionHandle.hpp"

namespace pljit {

PLjit::PLjit() = default;
PLjit::~PLjit() = default;

FunctionHandle PLjit::registerFunction(std::string) {
    return FunctionHandle(*this, functions.size() - 1);
}

} // namespace pljit
