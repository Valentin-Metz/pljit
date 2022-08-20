#ifndef PLJIT_CONSTANTPROPAGATIONOPTIMIZATIONPASS_HPP
#define PLJIT_CONSTANTPROPAGATIONOPTIMIZATIONPASS_HPP

#include "OptimizationPass.hpp"
namespace ast {

class ConstantPropagationOptimizationPass : public OptimizationPass {
    public:
    ~ConstantPropagationOptimizationPass() override = default;
    virtual void optimize(AST& ast) override;
};

} // namespace ast

#endif //PLJIT_CONSTANTPROPAGATIONOPTIMIZATIONPASS_HPP
