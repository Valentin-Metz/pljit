#include "FunctionDefinition.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"

namespace parse_tree {
using namespace lexer;
FunctionDefinition::FunctionDefinition(Lexer& l) {
    LexerToken t{l.nextToken()};

    switch (t.token_type) {
        case lexer::LexerToken::Keyword: {
            LexerKeywordToken k = static_cast<LexerKeywordToken>(t);
        }
    }
}
} // namespace parse_tree
