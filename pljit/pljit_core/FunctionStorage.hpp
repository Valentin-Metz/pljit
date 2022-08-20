#ifndef PLJIT_FUNCTIONSTORAGE_HPP
#define PLJIT_FUNCTIONSTORAGE_HPP

#include <memory>
#include <mutex>
#include <string>
#include <variant>
#include <vector>

namespace ast {
class AST;
}

namespace pljit {

class FunctionHandle;

class FunctionStorage {
    friend class PLjit;
    /// Stores functions either as source or once compiled as an AST
    /// The once_flag ensures that we only compile once
    std::vector<std::pair<std::unique_ptr<std::once_flag>, std::variant<std::string, std::unique_ptr<ast::AST>>>> functions;

    FunctionHandle registerFunction(std::string source_code);
};

} // namespace pljit

#endif //PLJIT_FUNCTIONSTORAGE_HPP
