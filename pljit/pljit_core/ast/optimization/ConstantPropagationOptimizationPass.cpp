#include "ConstantPropagationOptimizationPass.hpp"
#include "ConstantPropagationVisitor.hpp"

namespace ast {

void ConstantPropagationOptimizationPass::optimize(AST& ast) {
    ConstantPropagationVisitor constant_propagation_visitor;
    constant_propagation_visitor.visit(ast);
}

} // namespace ast
