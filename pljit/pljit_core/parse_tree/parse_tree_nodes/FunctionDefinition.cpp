#include "FunctionDefinition.hpp"
#include "../../lexer/tokens/LexerKeywordToken.hpp"
#include "Statement.hpp"

namespace parse_tree {
using namespace lexer;

FunctionDefinition::FunctionDefinition(Lexer& l) {
    while (!compound_statement) {
        std::unique_ptr<LexerToken> t = l.nextToken();
        switch (t->token_type) {
            case LexerToken::Error:
                throw pljit::Error(t->source_code_reference, pljit::Error::Lexer, static_cast<LexerErrorToken*>(t.get())->error_message);
            case LexerToken::Keyword: {
                LexerKeywordToken* k = static_cast<LexerKeywordToken*>(t.get());
                switch (k->keyword_type) {
                    case LexerKeywordToken::PARAM: {
                        if (parameter_declaration || variable_declaration || constant_declaration || compound_statement)
                            throw pljit::Error(k->source_code_reference, pljit::Error::ParseTree, "Parameters must only be defined once - before variables, constants and compound statement");
                        parameter_declaration.emplace(k->source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::VAR: {
                        if (variable_declaration || constant_declaration || compound_statement)
                            throw pljit::Error(k->source_code_reference, pljit::Error::ParseTree, "Variables must only be defined once - before constants and compound statement");
                        variable_declaration.emplace(k->source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::CONST: {
                        if (constant_declaration || compound_statement)
                            throw pljit::Error(k->source_code_reference, pljit::Error::ParseTree, "Constants must only be defined once - before the compound statement");
                        constant_declaration.emplace(k->source_code_reference, l);
                        break;
                    }
                    case LexerKeywordToken::BEGIN: {
                        compound_statement.emplace(k->source_code_reference, l);
                        break;
                    }
                    default: {
                        throw pljit::Error(k->source_code_reference, pljit::Error::ParseTree, "Unexpected keyword");
                    }
                }
                break;
            }
            default:
                throw pljit::Error(t->source_code_reference, pljit::Error::ParseTree, "Expected keyword");
        }
    }
    std::unique_ptr<LexerToken> t{l.nextToken()};
    if (t->token_type == LexerToken::Terminator) {
        terminator.emplace(t->source_code_reference);
    } else {
        throw pljit::Error(t->source_code_reference, pljit::Error::ParseTree, "Expected terminal symbol '.'");
    }
}
void FunctionDefinition::accept(const ParseTreeVisitor& visitor) const { visitor.visit(*this); }

FunctionDefinition::~FunctionDefinition() = default;

} // namespace parse_tree
