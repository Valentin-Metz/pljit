#ifndef PLJIT_SOURCECODEREFERENCE_HPP
#define PLJIT_SOURCECODEREFERENCE_HPP

#include "SourceCode.hpp"
#include <cstdlib>
#include <string_view>
namespace source_code {

struct SourceCodeReference {
    std::size_t byte_index;
    std::size_t reference_length;

    public:
    std::string_view resolve(SourceCode& c);
};

} // namespace source_code

#endif //PLJIT_SOURCECODEREFERENCE_HPP
