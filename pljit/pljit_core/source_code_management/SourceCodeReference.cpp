#include "SourceCodeReference.hpp"
std::string_view source_code::SourceCodeReference::resolve(SourceCode& c) {
    return c.source_code.substr(byte_index, reference_length);
}
