#include "PrimaryExpression.hpp"
#include "AdditiveExpression.hpp"
#include "lexer/tokens/LexerBracketToken.hpp"
#include "lexer/tokens/LexerLiteralToken.hpp"

namespace parse_tree {

PrimaryExpression::PrimaryExpression(std::unique_ptr<lexer::LexerToken> t, lexer::Lexer& l) {
    switch (t->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken&>(*t.get()).error_message);
        case lexer::LexerToken::Identifier: {
            identifier.emplace(t->source_code_reference);
            break;
        }
        case lexer::LexerToken::Literal: {
            literal.emplace(std::make_pair(t->source_code_reference, static_cast<lexer::LexerLiteralToken&>(*t.get()).value));
            break;
        }
        case lexer::LexerToken::Bracket: {
            lexer::LexerBracketToken& b = static_cast<lexer::LexerBracketToken&>(*t.get());
            if (b.bracket_type == lexer::LexerBracketToken::OPEN) {
                openBracket.emplace(t->source_code_reference);
                std::optional<std::unique_ptr<lexer::LexerToken>> closing_bracket;
                additiveExpression.emplace(std::make_unique<AdditiveExpression>(l, closing_bracket));
                closingBracket.emplace(closing_bracket.value()->source_code_reference);
                break;
            }
            [[fallthrough]];
        }
        default:
            throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected identifier, literal or additive-expression in brackets");
    }
}

PrimaryExpression::~PrimaryExpression() = default;

void PrimaryExpression::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
