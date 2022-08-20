#include "PLjit.hpp"
#include "FunctionHandle.hpp"
#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"

namespace pljit {

PLjit::PLjit() = default;
PLjit::~PLjit() = default;

FunctionHandle PLjit::registerFunction(std::string source_code) {
    //std::vector<std::pair<std::unique_ptr<std::once_flag>, std::variant<std::string, bool>>> v;
    //v.push_back(std::make_pair(std::make_unique<std::once_flag>(), source_code));
    //functions.push_back(std::make_pair(std::make_unique<std::once_flag>(), source_code));
    //std::vector<std::variant<std::string, ast::AST>> av;
    //av.push_back("x");

    return functionStorage->registerFunction(std::move(source_code));
}

} // namespace pljit
