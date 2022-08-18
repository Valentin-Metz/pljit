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
    std::optional<ParameterDeclaration> parameter_declaration;
    std::optional<VariableDeclaration> variable_declaration;
    std::optional<ConstantDeclaration> constant_declaration;
    std::optional<CompoundStatement> compound_statement;
    std::optional<TerminalSymbol> terminator;

    FunctionDefinition(lexer::Lexer& l);
    ~FunctionDefinition();
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_FUNCTIONDEFINITION_HPP
