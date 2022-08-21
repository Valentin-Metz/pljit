#ifndef PLJIT_IDENTIFIER_HPP
#define PLJIT_IDENTIFIER_HPP

#include "TerminalSymbol.hpp"
#include "include/PLjit_Error.hpp"
#include "lexer/Lexer.hpp"
#include "lexer/tokens/LexerErrorToken.hpp"
#include "lexer/tokens/LexerIdentifierToken.hpp"
#include "parse_tree/Visitor/ParseTreeVisitor.hpp"
#include <optional>
namespace parse_tree {

class Identifier {
    public:
    const TerminalSymbol identifier;
    Identifier(lexer::Lexer& l);
    Identifier(TerminalSymbol identifier);
    ~Identifier();
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_IDENTIFIER_HPP
