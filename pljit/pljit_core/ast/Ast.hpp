#ifndef PLJIT_AST_HPP
#define PLJIT_AST_HPP

#include "../parse_tree/ParseTree.hpp"
#include "ExecutionTable.hpp"
#include "SymbolTable.hpp"
#include "ast_nodes/Function.hpp"

namespace ast {

class AST {
    public:
    SymbolTable symbolTable;
    std::unique_ptr<Function> function;
    const source_code::SourceCode sourceCode;
    ~AST();
    AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode source_code);
    void accept(AstVisitor& visitor);
    void print();

    private:
    // Optimizes the AST
    void optimize();

    // The execution table must be copied for every execution
    std::optional<const ExecutionTable> executionTable;
    void generateExecutionTable();
    ExecutionTable getExecutionTable();
};

} // namespace ast

#endif //PLJIT_AST_HPP
