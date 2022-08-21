#include "StatementList.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../lexer/tokens/LexerSeparatorToken.hpp"
#include "Statement.hpp"
#include "include/PLjit_Error.hpp"

namespace parse_tree {

static const std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> generateStatementList(lexer::Lexer& l) {
    std::vector<std::pair<std::unique_ptr<const Statement>, const TerminalSymbol>> statement_list;
    bool done = false;
    while (!done) {
        std::optional<std::unique_ptr<lexer::LexerToken>> separator;
        std::unique_ptr<Statement> statement = std::make_unique<Statement>(l, separator);

        std::unique_ptr<lexer::LexerToken> t = std::move(separator.value());
        switch (t->token_type) {
            case lexer::LexerToken::Error:
                throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<lexer::LexerErrorToken*>(t.get())->error_message);

            /// ';'
            case lexer::LexerToken::Separator: {
                lexer::LexerSeparatorToken* s = static_cast<lexer::LexerSeparatorToken*>(t.get());
                if (s->separator_type != lexer::LexerSeparatorToken::SEMICOLON) {
                    throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Wrong separator");
                }
                statement_list.push_back(std::make_pair(std::move(statement), s->source_code_reference));
                break;
            }

            /// 'END'
            case lexer::LexerToken::Keyword: {
                lexer::LexerKeywordToken* k = static_cast<lexer::LexerKeywordToken*>(t.get());
                if (k->keyword_type != lexer::LexerKeywordToken::END) {
                    throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Wrong keyword");
                }
                done = true;
                statement_list.push_back(std::make_pair(std::move(statement), k->source_code_reference));
                break;
            }

            default:
                throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected ';' or 'END' keyword");
        }
    }
    return statement_list;
}

StatementList::StatementList(lexer::Lexer& l) : statementList(generateStatementList(l)) {}
void StatementList::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
