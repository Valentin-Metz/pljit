#ifndef PLJIT_TERMINALSYMBOL_HPP
#define PLJIT_TERMINALSYMBOL_HPP

#include "../../source_code_management/SourceCodeReference.hpp"
namespace parse_tree {

class TerminalSymbol {
    public:
    const source_code::SourceCodeReference source_code_reference;
    TerminalSymbol(source_code::SourceCodeReference source_code_reference) : source_code_reference(source_code_reference) {}
};

} // namespace parse_tree

#endif //PLJIT_TERMINALSYMBOL_HPP
