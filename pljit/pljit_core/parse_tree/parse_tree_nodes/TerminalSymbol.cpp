#include "TerminalSymbol.hpp"

namespace parse_tree {

TerminalSymbol::TerminalSymbol(source_code::SourceCodeReference source_code_reference) : source_code_reference(source_code_reference) {}
TerminalSymbol::~TerminalSymbol() = default;
void TerminalSymbol::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
