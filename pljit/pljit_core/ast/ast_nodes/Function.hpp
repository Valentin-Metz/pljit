#ifndef PLJIT_FUNCTION_HPP
#define PLJIT_FUNCTION_HPP

#include "Statement.hpp"
#include "ast/ast_core/ExecutionTable.hpp"
#include "ast/ast_core/SymbolTable.hpp"
#include "source_code_management/SourceCode.hpp"
#include <memory>
#include <vector>

namespace parse_tree {
class ParseTree;
class StatementList;
} // namespace parse_tree

namespace ast {

class Statement;

/// A function contains the statements of our program
class Function {
    public:
    std::vector<std::unique_ptr<Statement>> statements;
    ~Function();
    Function(const parse_tree::StatementList& statement_list, SymbolTable& symbol_table, source_code::SourceCode& source_code);
    void accept(AstVisitor& visitor);
    void execute(ExecutionTable& table);
};

} // namespace ast

#endif //PLJIT_FUNCTION_HPP
