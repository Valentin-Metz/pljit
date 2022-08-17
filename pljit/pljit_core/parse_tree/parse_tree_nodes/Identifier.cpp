#include "Identifier.hpp"

namespace parse_tree {

static const TerminalSymbol generateIdentifier(lexer::Lexer& l) {
    lexer::LexerToken i{l.nextToken()};
    switch (i.token_type) {
        case lexer::LexerToken::Error:
            throw CompilationError(i.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(i).error_message);
        case lexer::LexerToken::Identifier: {
            return TerminalSymbol(static_cast<lexer::LexerIdentifierToken&>(i).source_code_reference);
        }
        default:
            throw CompilationError(i.source_code_reference, CompilationError::ParseTree, "Expected identifier");
    }
}

Identifier::Identifier(lexer::Lexer& l) : identifier(generateIdentifier(l)) {}

} // namespace parse_tree
