#include "FunctionHandle.hpp"
#include "FunctionStorage.hpp"
#include "ast/Ast.hpp"
#include "error_management/Error.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/ParseTree.hpp"
#include "source_code_management/SourceCode.hpp"

namespace pljit {

FunctionHandle::FunctionHandle(FunctionStorage* storage, std::size_t index) : storage(storage), index(index) {}
FunctionHandle::~FunctionHandle() = default;

void FunctionHandle::compile() {
    /// Generate source code
    source_code::SourceCode source_code{std::move(std::get<std::string_view>(storage->functions[index].second))};

    /// Parse source code
    lexer::Lexer lexer{source_code};

    /// Construct parse tree
    parse_tree::ParseTree parse_tree{lexer};

    /// Construct abstract syntax tree
    std::unique_ptr<ast::AST> ast = std::make_unique<ast::AST>(parse_tree, std::move(source_code));

    /// Optimize abstract syntax tree
    ast->optimize();

    /// Generate execution table
    ast->generateExecutionTable();

    /// Store the abstract syntax tree
    storage->functions[index].second.emplace<std::unique_ptr<ast::AST>>(std::move(ast));
}

template <typename... Args>
std::variant<int64_t, Error> FunctionHandle::execute(Args... args) {
    compile();

    ast::AST& ast = *std::get<1>(storage->functions[index].second);

    /// Copy execution table and initialize it with parameters
    ast::ExecutionTable execution_table = ast.getExecutionTable();
    execution_table.template initialize(args...);

    /// Execute the program
    ast.function->execute(execution_table);

    return execution_table.result.value(); // todo: runtime-error
}

} // namespace pljit
