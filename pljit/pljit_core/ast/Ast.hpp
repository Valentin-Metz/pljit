#ifndef PLJIT_AST_HPP
#define PLJIT_AST_HPP

#include "ast_core/ExecutionTable.hpp"
#include "ast_core/SymbolTable.hpp"
#include "ast_nodes/Function.hpp"
#include "gtest/gtest.h"
namespace pljit {
class PLjit_FunctionHandle;
}
namespace parse_tree {
class ParseTree;
}

namespace ast {

/// Abstract syntax tree
class AST {
    FRIEND_TEST(AbstractSyntaxTreeTest, OptimizedResultEqualsUnoptimizedResult);
    FRIEND_TEST(AbstractSyntaxTreeTest, ExecutionTableContainsAllSymbols);
    friend class pljit::PLjit_FunctionHandle;

    // The execution table is used to evaluate an ast with user-given parameters
    std::optional<const ExecutionTable> executionTable;
    void generateExecutionTable();
    ExecutionTable getExecutionTable();

    public:
    SymbolTable symbolTable;
    std::unique_ptr<Function> function;

    // Constructors
    AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
    ~AST();

    // Visitor
    void accept(AstVisitor& visitor);

    // Print this ast in DOT format
    void print();

    // Optimize this ast
    void optimize();
};

} // namespace ast

#endif //PLJIT_AST_HPP
