#include "include/PLjit_FunctionHandle.hpp"
#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"
#include "include/PLjit.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/ParseTree.hpp"
#include "source_code_management/SourceCode.hpp"

namespace pljit {

PLjit_FunctionHandle::PLjit_FunctionHandle(FunctionStorage* storage, std::size_t index) : storage(storage), index(index) {}
PLjit_FunctionHandle::~PLjit_FunctionHandle() = default;

void PLjit_FunctionHandle::compile() {
    /// Get stored source code
    source_code::SourceCode& source_code = *std::get<1>(storage->functions[index]);

    /// Parse source code
    lexer::Lexer lexer{source_code};

    /// Construct parse tree
    parse_tree::ParseTree parse_tree{lexer};

    /// Construct abstract syntax tree
    std::unique_ptr<ast::AST> ast = std::make_unique<ast::AST>(parse_tree, source_code);

    /// Optimize abstract syntax tree
    ast->optimize();

    /// Generate execution table
    ast->generateExecutionTable();

    /// Store the abstract syntax tree
    std::get<2>(storage->functions[index]) = std::move(ast);
}

std::variant<std::int64_t, PLjit_Error> PLjit_FunctionHandle::execute(std::vector<std::int64_t> parameters) {
    try {
        /// Call compile() exactly once
        std::call_once(*std::get<0>(storage->functions[index]), &PLjit_FunctionHandle::compile, this);

        /// Load the AST
        ast::AST& ast = *std::get<2>(storage->functions[index]);

        /// Copy execution table
        ast::ExecutionTable execution_table = ast.getExecutionTable();

        /// Initialize the execution table with parameters
        execution_table.initialize(parameters);

        /// Execute the program
        ast.function->execute(execution_table);
        return execution_table.result.value();
    } catch (PLjit_Error error) {
        // todo: store source code in error and change ast so it stores a source code reference and change vector to permanently store source code as SourceCode
        return error;
    }
}

} // namespace pljit
