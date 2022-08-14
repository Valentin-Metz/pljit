#ifndef PLJIT_SOURCECODEREFERENCE_HPP
#define PLJIT_SOURCECODEREFERENCE_HPP

#include <cstdlib>

struct SourceCodeReference {
    std::size_t byte_index;
    std::size_t reference_length;
    std::size_t line_number;
    std::size_t char_number;
};

#endif //PLJIT_SOURCECODEREFERENCE_HPP
