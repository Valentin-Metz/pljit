#ifndef PLJIT_EXECUTIONTABLE_HPP
#define PLJIT_EXECUTIONTABLE_HPP
#include <optional>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace ast {

/// Class for evaluation of AST nodes
/// Stores variables used during execution
class ExecutionTable {
    // Parameter identifiers of the program
    const std::vector<std::string_view>& parameter_list;

    public:
    std::optional<std::int64_t> result;
    std::unordered_map<std::string_view, std::int64_t> table;

    /// Constructs an execution table based, which requires the named parameters of a program
    ExecutionTable(const std::vector<std::string_view>& parameter_list);

    /// Inserts a identifier-value pair into the table
    void insert(std::string_view identifier, std::int64_t value);
    /// Updates a identifier-value pair with a new value
    void update(std::string_view identifier, std::int64_t value);
    /// Retrieves the value for an identifier
    std::int64_t get(std::string_view identifier);

    /// Initializes the table with parameters given by the user (ordering is taken from parameter_list)
    void initialize(std::vector<std::int64_t> parameters);
};

} // namespace ast

#endif //PLJIT_EXECUTIONTABLE_HPP
