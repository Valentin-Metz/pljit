#ifndef FINAL_SOURCE_CODE_H
#define FINAL_SOURCE_CODE_H

#include <string_view>
namespace source_code {

class SourceCode {
    public:
    const std::string_view source_code;
    explicit SourceCode(std::string_view source_code);

    // Behave like the contained string if required
    operator const std::string_view&() const;

    // We don't want to copy source code around
    SourceCode(const SourceCode&) = delete;
    SourceCode& operator=(SourceCode&) = delete;

    // Moving is allowed
    SourceCode(SourceCode&&);
    // But if we override source code we are probably doing something wrong
    SourceCode& operator=(SourceCode&& other) = delete;
};

} // namespace source_code

#endif //FINAL_SOURCE_CODE_H
