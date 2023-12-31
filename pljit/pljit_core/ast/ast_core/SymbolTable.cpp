#include "SymbolTable.hpp"
#include "AstVisitor.hpp"

namespace ast {

void SymbolTable::check_read(std::string_view identifier, source_code::SourceCodeReference r) {
    auto result = table.find(identifier);
    /// Contained in table?
    if (result != table.end()) {
        /// Initialized?
        if (!std::get<1>(result->second))
            throw pljit::PLjit_Error(r, pljit::PLjit_Error::SymbolTable, "Attempted to read from uninitialized variable");
    } else {
        throw pljit::PLjit_Error(r, pljit::PLjit_Error::SymbolTable, "Attempted to access undeclared variable");
    }
}

void SymbolTable::check_assign(std::string_view identifier, source_code::SourceCodeReference r) {
    auto result = table.find(identifier);
    /// Contained in table and writeable
    if (result != table.end()) {
        if (std::get<0>(result->second) == Constant) {
            throw pljit::PLjit_Error(r, pljit::PLjit_Error::SymbolTable, "Attempted to write to constant");
        }
        std::get<1>(result->second) = true;
    } else {
        throw pljit::PLjit_Error(r, pljit::PLjit_Error::SymbolTable, "Attempted to access undeclared variable");
    }
}

void SymbolTable::declare(std::string_view identifier, DeclarationVariant declaration_variant, int64_t value, source_code::SourceCodeReference source_code_reference) {
    auto result = table.find(identifier);
    if (result != table.end())
        throw pljit::PLjit_Error(source_code_reference, pljit::PLjit_Error::SymbolTable, "Attempted to declare identifier twice");

    if (declaration_variant == Variable) {
        table.insert(std::make_pair(identifier, std::make_tuple(Variable, false, value, source_code_reference)));
    } else {
        table.insert(std::make_pair(identifier, std::make_tuple(declaration_variant, true, value, source_code_reference)));
    }
}

SymbolTable::SymbolTable(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) {
    if (parse_tree.root.parameter_declaration) {
        for (auto& identifier : parse_tree.root.parameter_declaration.value().declaratorList.declaratorList) {
            declare(identifier.first.identifier.source_code_reference.resolve(source_code), Parameter, 0, identifier.first.identifier.source_code_reference);
            parameters.push_back(identifier.first.identifier.source_code_reference.resolve(source_code));
        }
    }
    if (parse_tree.root.variable_declaration) {
        for (auto& identifier : parse_tree.root.variable_declaration.value().declaratorList.declaratorList) {
            declare(identifier.first.identifier.source_code_reference.resolve(source_code), Variable, 0, identifier.first.identifier.source_code_reference);
        }
    }
    if (parse_tree.root.constant_declaration) {
        for (auto& identifier : parse_tree.root.constant_declaration.value().initDeclaratorList.initDeclaratorList) {
            declare(identifier.first.identifier.identifier.source_code_reference.resolve(source_code), Constant, identifier.first.literal.literal.second, identifier.first.identifier.identifier.source_code_reference);
        }
    }
}

SymbolTable::~SymbolTable() = default;

void SymbolTable::accept(AstVisitor& visitor) {
    visitor.visit(*this);
}

} // namespace ast
