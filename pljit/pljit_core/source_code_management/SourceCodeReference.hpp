#ifndef PLJIT_SOURCECODEREFERENCE_HPP
#define PLJIT_SOURCECODEREFERENCE_HPP

#include <string_view>
namespace source_code {

class SourceCode;

struct SourceCodeReference {
    std::size_t byte_index;
    std::size_t reference_length;

    public:
    const std::string_view resolve(const SourceCode& c) const;
};

} // namespace source_code

#endif //PLJIT_SOURCECODEREFERENCE_HPP
