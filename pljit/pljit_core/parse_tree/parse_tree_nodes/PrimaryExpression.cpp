#include "PrimaryExpression.hpp"

namespace parse_tree {
PrimaryExpression::PrimaryExpression(lexer::LexerToken t, lexer::Lexer& l, std::optional<lexer::LexerToken>& separator) {
    switch (t.token_type) {
        case lexer::LexerToken::Assignment: break;
        case lexer::LexerToken::Error: break;
        case lexer::LexerToken::Keyword: break;
        case lexer::LexerToken::Identifier: break;
        case lexer::LexerToken::Literal: break;
        case lexer::LexerToken::Separator: break;
        case lexer::LexerToken::Declarator: break;
        case lexer::LexerToken::Arithmetic: break;
        case lexer::LexerToken::Bracket: break;
        case lexer::LexerToken::Terminator: break;
    }
}
} // namespace parse_tree
