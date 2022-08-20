#include "pljit_core/PLjit.hpp"
#include "pljit_core/ast/Ast.hpp"
#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/parse_tree/ParseTree.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <fstream>
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main([[maybe_unused]] int argc, char* argv[]) {
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    source_code::SourceCode source_code{valid_source};

    lexer::Lexer l{source_code};

    try {
        parse_tree::ParseTree parse_tree{l};
        //parse_tree.print();
        ast::AST ast{parse_tree, source_code};
        ast.optimize();
        ast.print();

        //std::cout << "success" << std::endl;
    } catch (pljit::Error e) {
        e.print();
        std::cout << "Terminated with error" << std::endl;
    }

    pljit::PLjit pljit;

    auto handle = pljit.registerFunction(valid_source);

    auto result = handle.execute({0});

    if (result.index() == 0) {
        std::cout << std::get<0>(result) << std::endl;
    } else {
        std::get<1>(result).print();
    }

    return 0;
}
//---------------------------------------------------------------------------
