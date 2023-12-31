#include "ExecutionTable.hpp"
#include "include/PLjit_Error.hpp"

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

void ExecutionTable::initialize(std::vector<std::int64_t> parameters) {
    if (parameters.size() > parameter_list.size()) throw pljit::PLjit_Error({0, 0}, pljit::PLjit_Error::Runtime, "Too many arguments");
    if (parameters.size() < parameter_list.size()) throw pljit::PLjit_Error({0, 0}, pljit::PLjit_Error::Runtime, "Not enough arguments");

    for (std::size_t i = 0; i < parameters.size(); ++i) {
        update(parameter_list[i], parameters[i]);
    }
}

} // namespace ast
