#include "Identifier.hpp"
#include "TerminalSymbol.hpp"

namespace parse_tree {

static const TerminalSymbol generateIdentifier(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> i{l.nextToken()};
    switch (i->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::PLjit_Error(i->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken&>(*i.get()).error_message);
        case lexer::LexerToken::Identifier: {
            return TerminalSymbol(static_cast<lexer::LexerIdentifierToken&>(*i.get()).source_code_reference);
        }
        default:
            throw pljit::PLjit_Error(i->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected identifier");
    }
}

Identifier::Identifier(lexer::Lexer& l) : identifier(generateIdentifier(l)) {}
Identifier::Identifier(TerminalSymbol identifier) : identifier(identifier) {}
Identifier::~Identifier() = default;
void Identifier::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
