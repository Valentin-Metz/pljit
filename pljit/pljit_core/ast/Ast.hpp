#ifndef PLJIT_AST_HPP
#define PLJIT_AST_HPP

#include "../parse_tree/ParseTree.hpp"
#include "ast_core/ExecutionTable.hpp"
#include "ast_core/SymbolTable.hpp"
#include "ast_nodes/Function.hpp"
namespace pljit {
class FunctionHandle;
}

namespace ast {

class AST {
    friend class pljit::FunctionHandle;

    public:
    SymbolTable symbolTable;
    std::unique_ptr<Function> function;
    const source_code::SourceCode sourceCode;

    AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode source_code);
    ~AST();

    void accept(AstVisitor& visitor);
    void print();
    void optimize();

    private:
    // The execution table manages variables during execution
    std::optional<const ExecutionTable> executionTable;

    void generateExecutionTable();
    ExecutionTable getExecutionTable();
};

} // namespace ast

#endif //PLJIT_AST_HPP
