#ifndef PLJIT_FUNCTION_HPP
#define PLJIT_FUNCTION_HPP

#include "../../source_code_management/SourceCode.hpp"
#include "../SymbolTable.hpp"
#include "../ExecutionTable.hpp"
#include "Statement.hpp"
#include <memory>
#include <vector>

namespace parse_tree {
class ParseTree;
class StatementList;
} // namespace parse_tree

namespace ast {

class Statement;

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
