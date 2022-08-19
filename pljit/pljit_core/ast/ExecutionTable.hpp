#ifndef PLJIT_EXECUTIONTABLE_HPP
#define PLJIT_EXECUTIONTABLE_HPP
#include <string_view>
#include <unordered_map>
#include <optional>

namespace ast {

class ExecutionTable {
    public:
    std::optional<int64_t> result;
    std::unordered_map<std::string_view, int64_t> table;

    ExecutionTable();

    void insert(std::string_view identifier, int64_t value);
    void update(std::string_view identifier, int64_t value);
    int64_t get(std::string_view identifier, int64_t value);
};

} // namespace ast

#endif //PLJIT_EXECUTIONTABLE_HPP
