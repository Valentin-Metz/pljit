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
    enum ArithmeticOperatorType {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
    };
    static std::pair<const SeparatorType, const TerminalSymbol> produceSeparator(lexer::Lexer& l);
    static const TerminalSymbol produceDeclarator(lexer::Lexer& l);
    static const TerminalSymbol produceAssignment(lexer::Lexer& l);
    static std::pair<const ArithmeticOperatorType, const TerminalSymbol> produceArithmeticOperator(lexer::Lexer& l);
};

} // namespace parse_tree

#endif //PLJIT_FACTORY_HPP
