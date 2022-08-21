#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit_FunctionHandle.hpp"

namespace pljit {

PLjit_FunctionHandle FunctionStorage::registerFunction(std::string_view source_code) {
    functions.push_back(std::make_pair(std::make_unique<std::once_flag>(), std::move(source_code)));
    return PLjit_FunctionHandle(this, functions.size() - 1);
}

} // namespace pljit