#include "FunctionHandle.hpp"
#include "FunctionStorage.hpp"

namespace pljit {

FunctionHandle::FunctionHandle(FunctionStorage* storage, std::size_t index) : storage(storage), index(index) {}
FunctionHandle::~FunctionHandle() = default;

} // namespace pljit
