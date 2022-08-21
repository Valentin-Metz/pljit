#ifndef PLJIT_TERMINALSYMBOL_HPP
#define PLJIT_TERMINALSYMBOL_HPP

#include "parse_tree/ParseTreeVisitor.hpp"
#include "source_code_management/SourceCodeReference.hpp"
namespace parse_tree {

class TerminalSymbol {
    public:
    TerminalSymbol(source_code::SourceCodeReference source_code_reference);
    ~TerminalSymbol();
    const source_code::SourceCodeReference source_code_reference;
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_TERMINALSYMBOL_HPP
