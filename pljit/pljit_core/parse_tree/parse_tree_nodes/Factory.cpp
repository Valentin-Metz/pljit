#include "Factory.hpp"
#include "../../error_management/PLjit_Error.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerSeparatorToken.hpp"

namespace parse_tree {

std::pair<const Factory::SeparatorType, const TerminalSymbol> Factory::produceSeparator(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> s{l.nextToken()};
    switch (s->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::PLjit_Error(s->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken*>(s.get())->error_message);
        case lexer::LexerToken::Separator: {
            TerminalSymbol t{s->source_code_reference};
            if (static_cast<lexer::LexerSeparatorToken*>(s.get())->separator_type == lexer::LexerSeparatorToken::COMMA)
                return std::make_pair(COMMA, t);
            else
                return std::make_pair(SEMICOLON, t);
        }
        default:
            throw pljit::PLjit_Error(s->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected separator");
    }
}
const TerminalSymbol Factory::produceDeclarator(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> d{l.nextToken()};
    switch (d->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::PLjit_Error(d->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken*>(d.get())->error_message);
        case lexer::LexerToken::Declarator: {
            return d->source_code_reference;
        }
        default:
            throw pljit::PLjit_Error(d->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected declarator");
    }
}
const TerminalSymbol Factory::produceAssignment(lexer::Lexer& l) {
    std::unique_ptr<lexer::LexerToken> a{l.nextToken()};
    switch (a->token_type) {
        case lexer::LexerToken::Error:
            throw pljit::PLjit_Error(a->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken*>(a.get())->error_message);
        case lexer::LexerToken::Assignment: {
            return a->source_code_reference;
        }
        default:
            throw pljit::PLjit_Error(a->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected assignment");
    }
}

} // namespace parse_tree
