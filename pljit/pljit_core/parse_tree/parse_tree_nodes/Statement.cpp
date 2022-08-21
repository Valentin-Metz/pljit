#include "Statement.hpp"
#include "AssignmentExpression.hpp"
#include "TerminalSymbol.hpp"
#include "lexer/tokens/LexerKeywordToken.hpp"

namespace parse_tree {

using namespace lexer;

Statement::Statement(lexer::Lexer& l, std::optional<std::unique_ptr<lexer::LexerToken>>& separator) {
    std::unique_ptr<LexerToken> t{l.nextToken()};
    switch (t->token_type) {
        case LexerToken::Error:
            throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::Lexer, static_cast<LexerErrorToken*>(t.get())->error_message);

        /// AdditiveExpression
        case LexerToken::Keyword: {
            if (static_cast<LexerKeywordToken*>(t.get())->keyword_type != LexerKeywordToken::RETURN)
                throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Wrong keyword");
            additiveExpression.emplace(std::make_pair(std::make_unique<TerminalSymbol>(t->source_code_reference), std::make_unique<AdditiveExpression>(l, separator)));
            break;
        }
        /// AssignmentExpression
        case LexerToken::Identifier: {
            assignmentExpression.emplace(std::make_unique<AssignmentExpression>(Identifier(t->source_code_reference), l, separator));
            break;
        }

        default:
            throw pljit::PLjit_Error(t->source_code_reference, pljit::PLjit_Error::ParseTree, "Expected identifier or 'RETURN'");
    }
}

Statement::~Statement() = default;

void Statement::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

} // namespace parse_tree
