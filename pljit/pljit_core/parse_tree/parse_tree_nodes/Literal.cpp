#include "Literal.hpp"
#include "../../error_management/Error.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerLiteralToken.hpp"

namespace parse_tree {

static const std::pair<TerminalSymbol, std::int64_t> generateLiteral(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> i{l.nextToken()};
    switch (i->token_type) {
        case lexer::LexerToken::Error:
            throw CompilationError(i->source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken*>(i.get())->error_message);
        case lexer::LexerToken::Literal: {
            return std::make_pair(i->source_code_reference, static_cast<lexer::LexerLiteralToken*>(i.get())->value);
        }
        default:
            throw CompilationError(i->source_code_reference, CompilationError::ParseTree, "Expected literal");
    }
}

Literal::Literal(lexer::Lexer& l) : literal(generateLiteral(l)) {}
Literal::Literal(std::pair<TerminalSymbol, std::int64_t> literal) : literal(literal) {}
void Literal::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
