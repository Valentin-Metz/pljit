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

template <typename... Args>
void FunctionHandle::compile(Args... args) {
    /// Generate source code
    source_code::SourceCode source_code{std::get<std::string_view>(storage->functions[index].second)};

    /// Parse source code
    lexer::Lexer lexer{source_code};

    /// Construct parse tree
    parse_tree::ParseTree{lexer};

    /// Construct abstract syntax tree
    //ast::AST ast{s};
}

template <typename... Args>
std::variant<int64_t, Error> FunctionHandle::execute(Args... args) {
    compile<>(args...);
    return std::variant<int64_t, Error>();
}

} // namespace pljit
