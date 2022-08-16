#include "DeclaratorList.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerIdentifierToken.hpp"
#include "../../lexer/tokens/LexerSeparatorToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"
#include <optional>

namespace parse_tree {

DeclaratorList::DeclaratorList(TerminalSymbol keyword, lexer::Lexer& l) : keyword(keyword) {
    bool done = false;
    while (!done) {
        std::optional<Identifier> identifier;
        std::optional<TerminalSymbol> separator;

        lexer::LexerToken i{l.nextToken()};
        switch (i.token_type) {
            case lexer::LexerToken::Error:
                throw CompilationError(i.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(i).error_message);
            case lexer::LexerToken::Identifier: {
                identifier.emplace(Identifier(TerminalSymbol(static_cast<lexer::LexerIdentifierToken&>(i).source_code_reference)));
                break;
            }
            default:
                throw CompilationError(i.source_code_reference, CompilationError::ParseTree, "Expected identifier");
        }
        lexer::LexerToken s{l.nextToken()};
        switch (s.token_type) {
            case lexer::LexerToken::Error:
                throw CompilationError(s.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(s).error_message);
            case lexer::LexerToken::Separator: {
                separator.emplace(TerminalSymbol(static_cast<lexer::LexerSeparatorToken&>(s).source_code_reference));
                if (static_cast<lexer::LexerSeparatorToken&>(s).separator_type == lexer::LexerSeparatorToken::SEMICOLON)
                    done = true;
                break;
            }
            default:
                throw CompilationError(i.source_code_reference, CompilationError::ParseTree, "Expected separator");
        }
        declarator_list.push_back(std::make_pair(identifier.value(), separator.value()));
    }
}

} // namespace parse_tree
