#ifndef PLJIT_FUNCTIONDEFINITION_HPP
#define PLJIT_FUNCTIONDEFINITION_HPP

#include "../../lexer/Lexer.hpp"
#include "CompoundStatement.hpp"
#include "ConstantDeclaration.hpp"
#include "DeclaratorList.hpp"
#include "TerminalSymbol.hpp"
#include <optional>
namespace parse_tree {

class FunctionDefinition {
    public:
    std::optional<DeclaratorList> parameter_declaration;
    std::optional<DeclaratorList> variable_declaration;
    std::optional<ConstantDeclaration> constant_declaration;
    std::optional<CompoundStatement> compound_statement;
    std::optional<TerminalSymbol> terminator;

    FunctionDefinition(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_FUNCTIONDEFINITION_HPP
