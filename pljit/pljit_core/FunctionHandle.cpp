#include "FunctionHandle.hpp"

namespace pljit {

FunctionHandle::FunctionHandle(PLjit& root, std::size_t index) : root(root), index(index) {
}

FunctionHandle::~FunctionHandle() {
}

} // namespace pljit
