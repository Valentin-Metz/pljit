#ifndef PLJIT_FUNCTION_HPP
#define PLJIT_FUNCTION_HPP

#include "../../source_code_management/SourceCode.hpp"
#include <memory>
#include <vector>
#include "Statement.hpp"

namespace parse_tree {
class ParseTree;
class StatementList;
} // namespace parse_tree

namespace ast {

class Statement;

class Function {
    std::vector<std::unique_ptr<Statement>> statements;

    public:
    ~Function();
    Function(const parse_tree::StatementList& statement_list, source_code::SourceCode& source_code);
};

} // namespace ast

#endif //PLJIT_FUNCTION_HPP
