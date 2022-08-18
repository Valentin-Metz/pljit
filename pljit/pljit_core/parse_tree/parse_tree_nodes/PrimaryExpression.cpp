#include "PrimaryExpression.hpp"
#include "../../lexer/tokens/LexerBracketToken.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerLiteralToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {
PrimaryExpression::PrimaryExpression(lexer::LexerToken t, lexer::Lexer& l) {
    switch (t.token_type) {
        case lexer::LexerToken::Error:
            throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(t).error_message);
        case lexer::LexerToken::Identifier: {
            identifier.emplace(t.source_code_reference);
            break;
        }
        case lexer::LexerToken::Literal: {
            literal.emplace(t.source_code_reference, static_cast<lexer::LexerLiteralToken&>(t).value);
            break;
        }
        case lexer::LexerToken::Bracket: {
            lexer::LexerBracketToken& b = static_cast<lexer::LexerBracketToken&>(t);
            if (b.bracket_type == lexer::LexerBracketToken::OPEN){
                openBracket.emplace(t.source_code_reference);
                //additiveExpression.emplace(std::make_unique<AdditiveExpression>(l, closingBracket));
                break;
            }
            [[fallthrough]];
        }
        default:
            throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected identifier, literal or additive-expression in brackets");
    }
}
} // namespace parse_tree
