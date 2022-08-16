#include "FunctionDefinition.hpp"
#include "../../lexer/tokens/LexerErrorToken.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "../../pljit_core_utility/CompilationError.hpp"

namespace parse_tree {
using namespace lexer;
FunctionDefinition::FunctionDefinition(Lexer& l) {
    while (!compound_statement) {
        LexerToken t{l.nextToken()};

        switch (t.token_type) {
            case LexerToken::Keyword: {
                LexerKeywordToken& k = static_cast<LexerKeywordToken&>(t);
                switch (k.keyword_type) {
                    case LexerKeywordToken::PARAM: break;
                    case LexerKeywordToken::VAR: break;
                    case LexerKeywordToken::CONST: break;
                    case LexerKeywordToken::BEGIN: break;

                    case LexerKeywordToken::END:
                    case LexerKeywordToken::RETURN: {
                        throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Unexpected keyword");
                    }
                }
            }
            case LexerToken::Error:
                throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<LexerErrorToken&>(t).error_message);
            default:
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected keyword");
        }
    }
    LexerToken t{l.nextToken()};
    if (t.token_type == LexerToken::Terminator) {
        terminator.emplace(TerminalSymbol(t.source_code_reference));
    } else {
        throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected terminal symbol '.'");
    }
}
} // namespace parse_tree
