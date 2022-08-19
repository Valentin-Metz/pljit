#include "PLjit.hpp"
#include "FunctionHandle.hpp"
#include "ast/Ast.hpp"

namespace pljit {

PLjit::PLjit() = default;
PLjit::~PLjit() = default;

FunctionHandle PLjit::registerFunction(std::string source_code) {
    std::variant<std::string, ast::AST> v{source_code};
    //functions.push_back(std::make_pair(std::atomic<FunctionState>(Registered),source_code));
    return FunctionHandle(*this, functions.size() - 1);
}

} // namespace pljit
