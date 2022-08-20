#ifndef PLJIT_EXECUTIONTABLE_HPP
#define PLJIT_EXECUTIONTABLE_HPP
#include <string_view>
#include <unordered_map>
#include <optional>

namespace ast {

class ExecutionTable {
    public:
    std::optional<std::int64_t> result;
    std::unordered_map<std::string_view, std::int64_t> table;

    ExecutionTable();

    void insert(std::string_view identifier, std::int64_t value);
    void update(std::string_view identifier, std::int64_t value);
    std::int64_t get(std::string_view identifier);

    /// Executes function with a variable amount of arguments
    template <typename... Args>
    int64_t initialize(Args... args);
};

} // namespace ast

#endif //PLJIT_EXECUTIONTABLE_HPP
