#include "FunctionHandle.hpp"
#include "FunctionStorage.hpp"
#include "error_management/Error.hpp"

namespace pljit {

FunctionHandle::FunctionHandle(FunctionStorage* storage, std::size_t index) : storage(storage), index(index) {}
FunctionHandle::~FunctionHandle() = default;

template <typename... Args>
std::variant<int64_t, Error> FunctionHandle::execute() {
    return std::variant<int64_t, Error>();
}

} // namespace pljit
