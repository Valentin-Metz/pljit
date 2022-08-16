#ifndef PLJIT_FUNCTIONDEFINITION_HPP
#define PLJIT_FUNCTIONDEFINITION_HPP

#include "../../lexer/Lexer.hpp"
#include "CompoundStatement.hpp"
#include "ConstantDeclaration.hpp"
#include "ParameterDeclaration.hpp"
#include "TerminalSymbol.hpp"
#include "VariableDeclaration.hpp"
#include <optional>
namespace parse_tree {

class FunctionDefinition {
    public:
    const std::optional<ParameterDeclaration> parameter_declaration;
    const std::optional<VariableDeclaration> variable_declaration;
    const std::optional<ConstantDeclaration> constant_declaration;
    const CompoundStatement compound_statement;
    const TerminalSymbol terminator;

    FunctionDefinition(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_FUNCTIONDEFINITION_HPP
