#include "SymbolTable.hpp"
#include "../pljit_core_utility/CompilationError.hpp"

namespace ast {
void SymbolTable::check_read(std::string_view identifier, source_code::SourceCodeReference r) {
    std::unordered_map<std::string_view, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference>>::const_iterator result = table.find(identifier);
    /// Contained in table?
    if (result != table.end()) {
        /// Initialized?
        if (!std::get<1>(result->second))
            throw CompilationError(r, CompilationError::SymbolTable, "Attempted to read from uninitialized variable");
    } else {
        throw CompilationError(r, CompilationError::SymbolTable, "Attempted to access undeclared variable");
    }
}

void SymbolTable::check_assign(std::string_view identifier, source_code::SourceCodeReference r) {
    std::unordered_map<std::string_view, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference>>::iterator result = table.find(identifier);
    /// Contained in table and writeable
    if (result != table.end()) {
        if (std::get<0>(result->second)) {
            std::get<1>(result->second) = true;
        } else {
            throw CompilationError(r, CompilationError::SymbolTable, "Attempted to write to constant");
        }
    } else {
        throw CompilationError(r, CompilationError::SymbolTable, "Attempted to access undeclared variable");
    }
}

void SymbolTable::declare(std::string_view identifier, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference> w_i_v_r) {
    std::unordered_map<std::string_view, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference>>::iterator result = table.find(identifier);
    if (result != table.end())
        throw CompilationError(std::get<3>(w_i_v_r), CompilationError::SymbolTable, "Attempted declare variable twice");
    table.insert(std::make_pair(identifier, w_i_v_r));
}

SymbolTable::SymbolTable(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code) {
    if (parse_tree.root.parameter_declaration) {
        for (auto& identifier : parse_tree.root.parameter_declaration.value().declaratorList.declaratorList) {
            declare(identifier.first.identifier.source_code_reference.resolve(source_code), std::make_tuple(true, true, 0, identifier.first.identifier.source_code_reference));
        }
    }
    if (parse_tree.root.variable_declaration) {
        for (auto& identifier : parse_tree.root.variable_declaration.value().declaratorList.declaratorList) {
            declare(identifier.first.identifier.source_code_reference.resolve(source_code), std::make_tuple(true, false, 0, identifier.first.identifier.source_code_reference));
        }
    }
    if (parse_tree.root.constant_declaration) {
        for (auto& identifier : parse_tree.root.constant_declaration.value().initDeclaratorList.initDeclaratorList) {
            declare(identifier.first.identifier.identifier.source_code_reference.resolve(source_code), std::make_tuple(false, true, identifier.first.literal.literal.second, identifier.first.identifier.identifier.source_code_reference));
        }
    }
}

} // namespace ast
