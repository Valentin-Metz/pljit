#ifndef PLJIT_FUNCTIONHANDLE_HPP
#define PLJIT_FUNCTIONHANDLE_HPP

#include <variant>
#include <cstdint>
namespace pljit {

class PLjit;
class FunctionStorage;
class Error;

class FunctionHandle {
    friend PLjit;
    friend FunctionStorage;
    FunctionStorage* storage;
    const std::size_t index;
    FunctionHandle(FunctionStorage* storage, std::size_t index);

    void compile();

    public:
    ~FunctionHandle();

    template <typename... Args>
    std::variant<std::int64_t, Error> execute(Args... args);
};

} // namespace pljit

#endif //PLJIT_FUNCTIONHANDLE_HPP
