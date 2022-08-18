#include "SourceCodeReference.hpp"
const std::string_view source_code::SourceCodeReference::resolve(const SourceCode& c) const {
    return c.source_code.substr(byte_index, reference_length);
}
