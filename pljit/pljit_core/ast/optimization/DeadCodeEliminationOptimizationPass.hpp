#ifndef PLJIT_DEADCODEELIMINATIONOPTIMIZATIONPASS_HPP
#define PLJIT_DEADCODEELIMINATIONOPTIMIZATIONPASS_HPP

#include "OptimizationPass.hpp"
namespace ast {

/// Dead code elimination utilizing visitor pattern
class DeadCodeEliminationOptimizationPass : public OptimizationPass {
    public:
    ~DeadCodeEliminationOptimizationPass() override = default;
    virtual void optimize(AST& ast) override;
};

} // namespace ast

#endif //PLJIT_DEADCODEELIMINATIONOPTIMIZATIONPASS_HPP
