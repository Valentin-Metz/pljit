#include "CompoundStatement.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {
using namespace lexer;

static const TerminalSymbol generateEnd(lexer::Lexer& l) {
    LexerToken t{l.nextToken()};
    switch (t.token_type) {
        case LexerToken::Error:
            throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<LexerErrorToken&>(t).error_message);
        case LexerToken::Keyword: {
            LexerKeywordToken& k = static_cast<LexerKeywordToken&>(t);
            switch (k.keyword_type) {
                case LexerKeywordToken::END:
                    return t.source_code_reference;
                default: {
                    throw CompilationError(k.source_code_reference, CompilationError::ParseTree, "Unexpected keyword");
                }
            }
        }
        default:
            throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected keyword");
    }
}

CompoundStatement::CompoundStatement(TerminalSymbol begin, lexer::Lexer& l) : begin(begin), statementList(l), end(generateEnd(l)) {}

} // namespace parse_tree
