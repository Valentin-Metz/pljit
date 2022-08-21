#ifndef PLJIT_PLJIT_FUNCTIONHANDLE_HPP
#define PLJIT_PLJIT_FUNCTIONHANDLE_HPP

#include <cstdint>
#include <variant>
#include <vector>

namespace pljit {

class PLjit;
class FunctionStorage;
class PLjit_Error;

/// Lightweight and cheap to copy handle to a function
class PLjit_FunctionHandle {
    friend PLjit;
    friend FunctionStorage;
    FunctionStorage* storage;
    const std::size_t index;
    PLjit_FunctionHandle(FunctionStorage* storage, std::size_t index);

    void compile();

    public:
    ~PLjit_FunctionHandle();

    /// Can be used to execute the stored source-code which will be compiled just-in-time
    std::variant<std::int64_t, PLjit_Error> execute(std::vector<std::int64_t> parameters);
};

} // namespace pljit

#endif //PLJIT_PLJIT_FUNCTIONHANDLE_HPP
