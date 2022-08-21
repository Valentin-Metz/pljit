#include "SourceCode.hpp"

namespace source_code {

SourceCode::SourceCode(std::string_view source_code) : source_code(std::move(source_code)) {}
SourceCode::operator const std::string_view&() const { return source_code; }

} // namespace source_code
