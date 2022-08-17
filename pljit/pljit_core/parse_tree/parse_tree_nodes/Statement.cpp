#include "Statement.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {
using namespace lexer;

Statement::Statement(lexer::Lexer& l, std::optional<LexerToken>& separator) {
    LexerToken t{l.nextToken()};
    switch (t.token_type) {
        case LexerToken::Error:
            throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<LexerErrorToken&>(t).error_message);

        /// AdditiveExpression
        case LexerToken::Keyword: {
            if (static_cast<LexerKeywordToken&>(t).keyword_type != LexerKeywordToken::RETURN)
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Wrong keyword");
            additiveExpression.emplace(t.source_code_reference, AdditiveExpression(l, separator));
            break;
        }
        /// AssignmentExpression
        case LexerToken::Identifier: {
            assignmentExpression.emplace(Identifier(t.source_code_reference), l, separator);
            break;
        }

        default:
            throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected identifier or 'RETURN'");
    }
}

} // namespace parse_tree
