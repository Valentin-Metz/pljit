#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/parse_tree/ParseTree.hpp"
#include "pljit_core/parse_tree/parse_tree_nodes/StatementList.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    source_code::SourceCode c{valid_source};

    CompilationError error = CompilationError(source_code::SourceCodeReference{0,5}, CompilationError::ParseTree, "Bad thing");
    error.print(c);
    //lexer::Lexer l{c};

    //parse_tree::ParseTree parse_tree{l};

    std::cout << "success" << std::endl;
    return 0;
}
//---------------------------------------------------------------------------
