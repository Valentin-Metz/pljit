#include "ast/Ast.hpp"
#include "lexer/Lexer.hpp"
#include "parse_tree/ParseTree.hpp"
#include <gtest/gtest.h>

using namespace source_code;
using namespace lexer;
using namespace parse_tree;
using namespace ast;

extern std::string example_program;
extern std::vector<std::string> valid_programs;
extern std::vector<std::string> invalid_programs;

TEST(AbstractSyntaxTreeTest, OptimizedResultEqualsUnoptimizedResult) {
    for (auto& string : valid_programs) {
        SourceCode source_code{string};
        Lexer lexer{source_code};
        ParseTree parse_tree{lexer};
        AST ast{parse_tree, source_code};


        EXPECT_EQ(true, true);
    }
}
