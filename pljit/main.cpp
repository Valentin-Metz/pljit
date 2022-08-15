#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <fstream>
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    SourceCode c{valid_source};
    Lexer l{c};

    while (l.nextToken().token_type != LexerToken::Error) {}

    std::cout << "success" << std::endl;
    return 0;
}
//---------------------------------------------------------------------------
