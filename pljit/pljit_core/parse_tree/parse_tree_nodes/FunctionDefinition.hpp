#ifndef PLJIT_FUNCTIONDEFINITION_HPP
#define PLJIT_FUNCTIONDEFINITION_HPP

#include "../../lexer/Lexer.hpp"
#include <optional>
namespace parse_tree {

class FunctionDefinition {
    public:
    FunctionDefinition(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_FUNCTIONDEFINITION_HPP
