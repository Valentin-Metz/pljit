#ifndef PLJIT_FUNCTION_HPP
#define PLJIT_FUNCTION_HPP

#include "../../parse_tree/ParseTree.hpp"
#include <vector>
namespace ast {

class Statement;

class Function {
    //std::vector<std::unique_ptr<Statement>> statements;

    public:
    Function(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
};

} // namespace ast

#endif //PLJIT_FUNCTION_HPP
