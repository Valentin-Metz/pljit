#include "Ast.hpp"

namespace ast {

AST::AST(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) : symbolTable(parse_tree, source_code), function(std::make_unique<Function>(parse_tree, source_code)) {}

} // namespace ast