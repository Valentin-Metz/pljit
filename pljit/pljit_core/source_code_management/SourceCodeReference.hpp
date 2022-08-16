#ifndef PLJIT_SOURCECODEREFERENCE_HPP
#define PLJIT_SOURCECODEREFERENCE_HPP

#include <cstdlib>
namespace source_code {

struct SourceCodeReference {
    std::size_t byte_index;
    std::size_t reference_length;
};

} // namespace source_code

#endif //PLJIT_SOURCECODEREFERENCE_HPP
