#include "StatementList.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../lexer/tokens/LexerSeparatorToken.hpp"

namespace parse_tree {

static const std::vector<std::pair<const Statement, const TerminalSymbol>> generateStatementList(lexer::Lexer& l) {
    std::vector<std::pair<const Statement, const TerminalSymbol>> statement_list;
    bool done = false;
    while (!done) {
        std::optional<TerminalSymbol> separator;

        Statement statement{l};
        lexer::LexerToken t{l.nextToken()};
        switch (t.token_type) {
            case lexer::LexerToken::Error:
                throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(t).error_message);

            /// ';'
            case lexer::LexerToken::Separator: {
                lexer::LexerSeparatorToken s = static_cast<lexer::LexerSeparatorToken&>(t);
                if (s.separator_type != lexer::LexerSeparatorToken::SEMICOLON) {
                    throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Wrong separator");
                }
                statement_list.push_back(std::make_pair(statement, s.source_code_reference));
                break;
            }

            /// 'END'
            case lexer::LexerToken::Keyword: {
                lexer::LexerKeywordToken k = static_cast<lexer::LexerKeywordToken&>(t);
                if (k.keyword_type != lexer::LexerKeywordToken::END) {
                    throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Wrong keyword");
                }
                done = true;
                statement_list.push_back(std::make_pair(statement, k.source_code_reference));
                break;
            }

            default:
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected ';' or 'END' keyword");
        }
    }
}

StatementList::StatementList(lexer::Lexer& l) : statementList(generateStatementList(l)) {}

} // namespace parse_tree
