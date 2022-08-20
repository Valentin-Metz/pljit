#include "ExecutionTable.hpp"
#include <stdarg.h>

namespace ast {

ExecutionTable::ExecutionTable() = default;

void ExecutionTable::insert(std::string_view identifier, int64_t value) {
    table.insert(std::make_pair(identifier, value));
}

void ExecutionTable::update(std::string_view identifier, int64_t value) {
    table.find(identifier)->second = value;
}

int64_t ExecutionTable::get(std::string_view identifier) {
    return table.find(identifier)->second;
}
template <typename... Args>
int64_t ExecutionTable::initialize(Args... args) {
    insert(args...);
}

} // namespace ast
