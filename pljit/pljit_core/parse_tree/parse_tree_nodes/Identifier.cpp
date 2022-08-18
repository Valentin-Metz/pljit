#include "Identifier.hpp"

namespace parse_tree {

static const TerminalSymbol generateIdentifier(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> i{l.nextToken()};
    switch (i->token_type) {
        case lexer::LexerToken::Error:
            throw CompilationError(i->source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken*>(i.get())->error_message);
        case lexer::LexerToken::Identifier: {
            return TerminalSymbol(static_cast<lexer::LexerIdentifierToken*>(i.get())->source_code_reference);
        }
        default:
            throw CompilationError(i->source_code_reference, CompilationError::ParseTree, "Expected identifier");
    }
}

Identifier::Identifier(lexer::Lexer& l) : identifier(generateIdentifier(l)) {}
Identifier::Identifier(TerminalSymbol identifier) : identifier(identifier) {}

} // namespace parse_tree
