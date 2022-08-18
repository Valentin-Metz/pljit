#ifndef FINAL_SOURCE_CODE_H
#define FINAL_SOURCE_CODE_H

#include "../pljit_core_utility/NonCopyable.hpp"
#include <string>
#include <utility>
namespace source_code {

class SourceCode : public NonCopyable {
    public:
    const std::string_view source_code;
    explicit SourceCode(std::string_view source_code) : source_code(std::move(source_code)) {}

    operator const std::string_view&() const { return source_code; };
};

} // namespace source_code

#endif //FINAL_SOURCE_CODE_H
