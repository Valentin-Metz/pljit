#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

#include <atomic>
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

    /// Indicates state of registered function
    enum FunctionState {
        Registered,
        Compiling,
        Complete,
        Failed,
    };

    /// Stores atomic state of registered functions
    std::vector<std::pair<std::atomic<FunctionState>, std::variant<std::string, ast::AST>>> functions;

    // Constructors
    public:
    PLjit();
    ~PLjit();

    /// Registers a function by source code and returns a callable handle
    FunctionHandle registerFunction(std::string source_code);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
