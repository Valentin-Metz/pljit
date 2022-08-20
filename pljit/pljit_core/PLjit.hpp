#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

#include <memory>
#include <string>

namespace pljit {

class FunctionHandle;
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
    FunctionHandle registerFunction(std::string source_code);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
