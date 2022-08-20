#ifndef PLJIT_OPTIMIZATIONPASS_HPP
#define PLJIT_OPTIMIZATIONPASS_HPP

namespace ast {

class AST;

class OptimizationPass {
    public:
    virtual ~OptimizationPass() = default;
    virtual void optimize(AST& ast) = 0;
};

} // namespace ast

#endif //PLJIT_OPTIMIZATIONPASS_HPP
