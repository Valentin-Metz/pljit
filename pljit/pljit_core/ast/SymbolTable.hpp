#ifndef PLJIT_SYMBOLTABLE_HPP
#define PLJIT_SYMBOLTABLE_HPP
#include "../parse_tree/ParseTree.hpp"
#include "../source_code_management/SourceCodeReference.hpp"
#include <string_view>
#include <tuple>
#include <unordered_map>

namespace ast {

class SymbolTable {
    /// Identifier -> (Writeable, Initialized, Value, SourceCodeReference)
    std::unordered_map<std::string_view, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference>> table;

    public:
    SymbolTable(parse_tree::ParseTree& parse_tree, source_code::SourceCode& source_code);
    void check_read(std::string_view identifier, source_code::SourceCodeReference r);
    void check_assign(std::string_view identifier, source_code::SourceCodeReference r);
    void declare(std::string_view identifier, std::tuple<bool, bool, int64_t, source_code::SourceCodeReference> w_i_v_r);
};

} // namespace ast

#endif //PLJIT_SYMBOLTABLE_HPP
