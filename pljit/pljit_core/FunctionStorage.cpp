#include "FunctionStorage.hpp"
#include "FunctionHandle.hpp"
#include "ast/Ast.hpp"

namespace pljit {

FunctionHandle FunctionStorage::registerFunction(std::string source_code) {
    return FunctionHandle(this, functions.size() - 1);
}

} // namespace pljit
