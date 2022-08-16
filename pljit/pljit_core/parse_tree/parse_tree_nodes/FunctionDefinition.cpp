#include "FunctionDefinition.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"

namespace parse_tree {
using namespace lexer;
FunctionDefinition::FunctionDefinition(Lexer& l) {
    LexerToken t{l.nextToken()};

    switch (t.token_type) {
        case lexer::LexerToken::Keyword: {
            LexerKeywordToken& k = static_cast<LexerKeywordToken&>(t);
            switch (k.keyword_type) {
                case LexerKeywordToken::PARAM: break;
                case LexerKeywordToken::VAR: break;
                case LexerKeywordToken::CONST: break;
                case LexerKeywordToken::BEGIN: break;
                case LexerKeywordToken::END: break;
                case LexerKeywordToken::RETURN: break;
            }
        }
    }
}
} // namespace parse_tree
