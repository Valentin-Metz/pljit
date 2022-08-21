#ifndef PLJIT_FUNCTIONSTORAGE_HPP
#define PLJIT_FUNCTIONSTORAGE_HPP

#include <memory>
#include <mutex>
#include <string_view>
#include <variant>
#include <vector>

namespace source_code {
class SourceCode;
}
namespace ast {
class AST;
}

namespace pljit {

class PLjit_FunctionHandle;

class FunctionStorage {
    friend class PLjit;
    friend class PLjit_FunctionHandle;

    /// Stores functions either as source or once compiled as an AST
    /// The once_flag ensures that we only compile once
    std::vector<std::tuple<std::unique_ptr<std::once_flag>, std::unique_ptr<source_code::SourceCode>, std::unique_ptr<ast::AST>>> functions;

    PLjit_FunctionHandle registerFunction(std::string_view source_code);
};

} // namespace pljit

#endif //PLJIT_FUNCTIONSTORAGE_HPP
