#ifndef PLJIT_EXECUTIONTABLE_HPP
#define PLJIT_EXECUTIONTABLE_HPP
#include <optional>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace ast {

class ExecutionTable {
    const std::vector<std::string_view>& parameter_list;

    public:
    std::optional<std::int64_t> result;
    std::unordered_map<std::string_view, std::int64_t> table;

    ExecutionTable(const std::vector<std::string_view>& parameter_list);

    void insert(std::string_view identifier, std::int64_t value);
    void update(std::string_view identifier, std::int64_t value);
    std::int64_t get(std::string_view identifier);

    void initialize(std::vector<std::int64_t> parameters);
};

} // namespace ast

#endif //PLJIT_EXECUTIONTABLE_HPP
