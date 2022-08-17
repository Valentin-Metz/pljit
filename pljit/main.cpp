#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include "pljit_core/parse_tree/parse_tree_nodes/StatementList.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    source_code::SourceCode c{valid_source};
    lexer::Lexer l{c};

    while (l.nextToken().token_type != lexer::LexerToken::Error) {}

    class AdditiveExpression {
        public:
        std::unique_ptr<AdditiveExpression> additiveExpression;
        AdditiveExpression();
    };



    std::cout << "success" << std::endl;
    return 0;
}
//---------------------------------------------------------------------------
