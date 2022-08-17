#ifndef PLJIT_FACTORY_HPP
#define PLJIT_FACTORY_HPP

#include "../../lexer/Lexer.hpp"
#include "TerminalSymbol.hpp"
namespace parse_tree {

/// This factory produces nodes for terminals which do not get their own node-type according to the assignment
class Factory {
    public:
    enum SeparatorType {
        COMMA,
        SEMICOLON
    };
    static std::pair<const SeparatorType, const TerminalSymbol> produceSeparator(lexer::Lexer& l);
    static const TerminalSymbol produceDeclarator(lexer::Lexer& l);
    static const TerminalSymbol produceAssignment(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_FACTORY_HPP
