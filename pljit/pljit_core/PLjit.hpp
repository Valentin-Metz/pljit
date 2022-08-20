#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

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

/// PL/0 just-in-time compiler
class PLjit {
    friend FunctionHandle;

    /// Stores functions either as source or once compiled as an AST
    /// The once_flag ensures that we only compile once
    std::vector<std::pair<std::unique_ptr<std::once_flag>, std::variant<std::string, std::unique_ptr<ast::AST>>>> functions;

    // Constructors
    public:
    PLjit();
    ~PLjit();

    /// Registers a function by source code and returns a callable handle
    FunctionHandle registerFunction(std::string source_code);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
