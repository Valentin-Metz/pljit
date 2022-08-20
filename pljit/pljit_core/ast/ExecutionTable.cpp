#include "ExecutionTable.hpp"
#include "../error_management/RuntimeError.hpp"

namespace ast {

ExecutionTable::ExecutionTable(const std::vector<std::string_view>& parameter_list) : parameter_list(parameter_list) {}

void ExecutionTable::insert(std::string_view identifier, int64_t value) {
    table.insert(std::make_pair(identifier, value));
}

void ExecutionTable::update(std::string_view identifier, int64_t value) {
    table.find(identifier)->second = value;
}

int64_t ExecutionTable::get(std::string_view identifier) {
    return table.find(identifier)->second;
}
void ExecutionTable::initialize(std::int64_t value) {
    if (parameter_counter >= parameter_list.size()) throw RuntimeError("too many arguments");
    update(parameter_list[parameter_counter++], value);
}

} // namespace ast
