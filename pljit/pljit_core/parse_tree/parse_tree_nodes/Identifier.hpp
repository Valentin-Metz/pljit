#ifndef PLJIT_IDENTIFIER_HPP
#define PLJIT_IDENTIFIER_HPP

#include "../../lexer/Lexer.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerIdentifierToken.hpp"
#include "../../error_management/CompilationError.hpp"
#include "../ParseTreeVisitor.hpp"
#include "TerminalSymbol.hpp"
#include <optional>
namespace parse_tree {

class Identifier {
    public:
    const TerminalSymbol identifier;
    ~Identifier();
    Identifier(lexer::Lexer& l);
    Identifier(TerminalSymbol identifier);
    void accept(const ParseTreeVisitor& visitor) const;
};

} // namespace parse_tree

#endif //PLJIT_IDENTIFIER_HPP
