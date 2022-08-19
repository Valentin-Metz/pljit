#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

#include <atomic>
#include <optional>
#include <string>
#include <vector>

namespace ast {
class AST;
}

namespace pljit {

class FunctionHandle;

class PLjit {
    /// Indicates state of registered function
    enum FunctionState {
        Registered,
        Compiling,
        Complete,
        Failed,
    };
    /// Stores atomic state of registered functions
    std::vector<std::pair<std::atomic<FunctionState>, std::optional<ast::AST>>> functions;

    public:
    PLjit();
    ~PLjit();

    FunctionHandle registerFunction(std::string);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
