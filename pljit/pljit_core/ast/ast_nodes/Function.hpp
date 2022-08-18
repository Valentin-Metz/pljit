#ifndef PLJIT_FUNCTION_HPP
#define PLJIT_FUNCTION_HPP

#include "../../source_code_management/SourceCode.hpp"
#include <vector>
#include <memory>

namespace parse_tree {
class ParseTree;
}

namespace ast {

class Statement;

class Function {
    std::vector<std::unique_ptr<Statement>> statements;

    public:
    ~Function();
    Function(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
};

} // namespace ast

#endif //PLJIT_FUNCTION_HPP
