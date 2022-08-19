#ifndef PLJIT_PLJIT_HPP
#define PLJIT_PLJIT_HPP

#include <string>
#include <vector>
namespace pljit {

class FunctionHandle;

class PLjit {
    std::vector<int> functions;

    public:
    PLjit();
    ~PLjit();
    FunctionHandle registerFunction(std::string);
};

} // namespace pljit

#endif //PLJIT_PLJIT_HPP
