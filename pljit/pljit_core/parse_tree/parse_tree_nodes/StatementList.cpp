#include "StatementList.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../lexer/tokens/LexerSeparatorToken.hpp"

namespace parse_tree {

static const std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> generateStatementList(lexer::Lexer& l) {
    std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> statement_list;
    bool done = false;
    while (!done) {
        std::optional<lexer::LexerToken> separator;
        std::unique_ptr<Statement> statement = std::make_unique<Statement>(l, separator);

        lexer::LexerToken t = separator.value();
        switch (t.token_type) {
            case lexer::LexerToken::Error:
                throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<lexer::LexerErrorToken&>(t).error_message);

            /// ';'
            case lexer::LexerToken::Separator: {
                lexer::LexerSeparatorToken s = static_cast<lexer::LexerSeparatorToken&>(t);
                if (s.separator_type != lexer::LexerSeparatorToken::SEMICOLON) {
                    throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Wrong separator");
                }
                std::vector<std::unique_ptr<Statement>> v;
                v.push_back(std::move(statement));
                statement_list.push_back(std::make_pair(std::move(statement), s.source_code_reference));
                break;
            }

            /// 'END'
            case lexer::LexerToken::Keyword: {
                lexer::LexerKeywordToken k = static_cast<lexer::LexerKeywordToken&>(t);
                if (k.keyword_type != lexer::LexerKeywordToken::END) {
                    throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Wrong keyword");
                }
                done = true;
                statement_list.push_back(std::make_pair(std::move(statement), k.source_code_reference));
                break;
            }

            default:
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected ';' or 'END' keyword");
        }
    }
    return statement_list;
}

StatementList::StatementList(lexer::Lexer& l) : statementList(generateStatementList(l)) {}

} // namespace parse_tree