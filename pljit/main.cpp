#include "pljit_core/ast/Ast.hpp"
#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/parse_tree/ParseTree.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <fstream>
#include <iostream>
#include "pljit_core/PLjit.hpp"
#include "pljit_core/error_management/Error.hpp"

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
        //ast.print();

        //std::cout << "success" << std::endl;
    } catch (CompilationError e) {
        e.print(source_code);
        std::cout << "Terminated with error" << std::endl;
    }

    pljit::PLjit pljit;

    auto handle = pljit.registerFunction(valid_source);
    //auto result = handle.execute(2,2,2,2);

    return 0;
}
//---------------------------------------------------------------------------
