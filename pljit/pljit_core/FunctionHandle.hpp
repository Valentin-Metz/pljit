#ifndef PLJIT_FUNCTIONHANDLE_HPP
#define PLJIT_FUNCTIONHANDLE_HPP

#include "PLjit.hpp"
namespace pljit {

class FunctionHandle {
    friend PLjit;
    friend FunctionStorage;
    const FunctionStorage* storage;
    const std::size_t index;
    FunctionHandle(FunctionStorage* storage, std::size_t index);
    ~FunctionHandle();
};

} // namespace pljit

#endif //PLJIT_FUNCTIONHANDLE_HPP
