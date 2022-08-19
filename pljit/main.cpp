#include "pljit_core/ast/Ast.hpp"
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

    source_code::SourceCode source_code{valid_source};

    //CompilationError error = CompilationError(source_code::SourceCodeReference{0,5}, CompilationError::ParseTree, "Bad thing");
    //error.print(source_code);
    lexer::Lexer l{source_code};

    try {
        parse_tree::ParseTree parse_tree{l};
        parse_tree.print();
        ast::AST ast{parse_tree, source_code};

        std::cout << "success" << std::endl;
    } catch (CompilationError e) {
        e.print(source_code);
        std::cout << "error" << std::endl;
    }

    return 0;
}
//---------------------------------------------------------------------------
