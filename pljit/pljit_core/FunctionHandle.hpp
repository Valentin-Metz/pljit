#ifndef PLJIT_FUNCTIONHANDLE_HPP
#define PLJIT_FUNCTIONHANDLE_HPP

#include "PLjit.hpp"
#include <variant>
namespace pljit {

class Error;

class FunctionHandle {
    friend PLjit;
    friend FunctionStorage;
    const FunctionStorage* storage;
    const std::size_t index;
    FunctionHandle(FunctionStorage* storage, std::size_t index);
    ~FunctionHandle();

    template <typename... Args>
    void compile(Args... args);

    public:
    template <typename... Args>
    std::variant<int64_t, Error> execute(Args... args);
};

} // namespace pljit

#endif //PLJIT_FUNCTIONHANDLE_HPP
