#ifndef PLJIT_FUNCTIONHANDLE_HPP
#define PLJIT_FUNCTIONHANDLE_HPP

#include "PLjit.hpp"
namespace pljit {

class FunctionHandle {
    private:
    friend PLjit;
    const PLjit& root;
    const std::size_t index;
    FunctionHandle(PLjit& root, std::size_t index);
    ~FunctionHandle();
};

} // namespace pljit

#endif //PLJIT_FUNCTIONHANDLE_HPP
