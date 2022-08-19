#ifndef PLJIT_EXECUTIONTABLE_HPP
#define PLJIT_EXECUTIONTABLE_HPP
#include <unordered_map>
#include <string_view>

namespace ast {

class ExecutionTable {
    private:
    std::unordered_map<std::string_view, int64_t> table;
    public:
    ExecutionTable();
    void insert(std::string_view identifier, int64_t value);
    void update(std::string_view identifier, int64_t value);
    int64_t get(std::string_view identifier, int64_t value);
};

} // namespace ast

#endif //PLJIT_EXECUTIONTABLE_HPP
