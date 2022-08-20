#include "DeadCodeEliminationOptimizationPass.hpp"
#include "DeadCodeEliminationVisitor.hpp"

namespace ast {

void DeadCodeEliminationOptimizationPass::optimize(AST& ast) {
    DeadCodeEliminationVisitor dead_code_elimination_visitor;
    dead_code_elimination_visitor.visit(ast);
}

} // namespace ast
