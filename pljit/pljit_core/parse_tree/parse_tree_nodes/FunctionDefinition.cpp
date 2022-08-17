#include "FunctionDefinition.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"

namespace parse_tree {
using namespace lexer;

FunctionDefinition::FunctionDefinition(Lexer& l) {
    while (!compound_statement) {
        LexerToken t{l.nextToken()};
        switch (t.token_type) {
            case LexerToken::Error:
                throw CompilationError(t.source_code_reference, CompilationError::Lexer, static_cast<LexerErrorToken&>(t).error_message);
            case LexerToken::Keyword: {
                LexerKeywordToken& k = static_cast<LexerKeywordToken&>(t);
                switch (k.keyword_type) {
                    case LexerKeywordToken::PARAM: {
                        if (parameter_declaration || variable_declaration || constant_declaration || compound_statement)
                            throw CompilationError(k.source_code_reference, CompilationError::ParseTree, "Parameters must only be defined once - before variables, constants and compound statement");
                        parameter_declaration.emplace(k.source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::VAR: {
                        if (variable_declaration || constant_declaration || compound_statement)
                            throw CompilationError(k.source_code_reference, CompilationError::ParseTree, "Variables must only be defined once - before constants and compound statement");
                        variable_declaration.emplace(k.source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::CONST: {
                        if (constant_declaration || compound_statement)
                            throw CompilationError(k.source_code_reference, CompilationError::ParseTree, "Constants must only be defined once - before the compound statement");
                        constant_declaration.emplace(k.source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::BEGIN: {
                        compound_statement.emplace(k.source_code_reference, l);
                        break;
                    }
                    default: {
                        throw CompilationError(k.source_code_reference, CompilationError::ParseTree, "Unexpected keyword");
                    }
                }
                break;
            }
            default:
                throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected keyword");
        }
    }
    LexerToken t{l.nextToken()};
    if (t.token_type == LexerToken::Terminator) {
        terminator.emplace(t.source_code_reference);
    } else {
        throw CompilationError(t.source_code_reference, CompilationError::ParseTree, "Expected terminal symbol '.'");
    }
}

} // namespace parse_tree
