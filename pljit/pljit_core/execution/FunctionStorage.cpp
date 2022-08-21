#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit_FunctionHandle.hpp"
#include "source_code_management/SourceCode.hpp"

namespace pljit {

PLjit_FunctionHandle FunctionStorage::registerFunction(std::string_view source_code) {
    functions.push_back(std::make_tuple(std::make_unique<std::once_flag>(), std::make_unique<source_code::SourceCode>(std::move(source_code)), nullptr));
    return PLjit_FunctionHandle(this, functions.size() - 1);
}

} // namespace pljit
