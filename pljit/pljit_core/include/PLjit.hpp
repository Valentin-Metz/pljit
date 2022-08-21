#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

#include <memory>
#include <string_view>

namespace pljit {

class PLjit_FunctionHandle;
class FunctionStorage;

/// PL/0 just-in-time compiler
class PLjit {
    // Stores executable functions
    std::unique_ptr<FunctionStorage> functionStorage;

    // Constructors
    public:
    PLjit();
    ~PLjit();

    /// Registers a function by source code and returns a callable handle
    PLjit_FunctionHandle registerFunction(std::string_view source_code);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
