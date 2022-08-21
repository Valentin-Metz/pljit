#ifndef PLJIT_SYMBOLTABLE_HPP
#define PLJIT_SYMBOLTABLE_HPP
#include "parse_tree/ParseTree.hpp"
#include "source_code_management/SourceCodeReference.hpp"
#include <string_view>
#include <tuple>
#include <unordered_map>

namespace ast {
class AstVisitor;

/// The symbol table stores all defined parameters, variables and constants of the program
class SymbolTable {
    public:
    enum DeclarationVariant {
        Parameter,
        Variable,
        Constant,
    };
    /// Identifier -> (DeclarationVariant, Initialized, Value, SourceCodeReference)
    std::unordered_map<std::string_view, std::tuple<DeclarationVariant, bool, int64_t, source_code::SourceCodeReference>> table;
    /// Names for function parameters in order
    std::vector<std::string_view> parameters;

    public:
    // Constructor
    SymbolTable(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
    ~SymbolTable();

    /// Check if we can read an identifier (identifier must be initialized)
    void check_read(std::string_view identifier, source_code::SourceCodeReference r);
    /// Check if we can write to an identifier (identifier must not be a constant)
    void check_assign(std::string_view identifier, source_code::SourceCodeReference r);
    /// Declares a new identifier (identifier must not have been declared before)
    void declare(std::string_view identifier, DeclarationVariant declaration_variant, int64_t value, source_code::SourceCodeReference source_code_reference);

    // Visitor
    void accept(AstVisitor& visitor);
};

} // namespace ast

#endif //PLJIT_SYMBOLTABLE_HPP
