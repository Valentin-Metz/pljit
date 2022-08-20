#include "pljit_core/FunctionHandle.hpp"
#include "pljit_core/PLjit.hpp"
#include "pljit_core/error_management/PLjit_Error.hpp"
#include <fstream>
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main([[maybe_unused]] int argc, char* argv[]) {
    std::ifstream ifs(argv[1]);
    std::string valid_source((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    //source_code::SourceCode source_code{valid_source};

    //lexer::Lexer l{source_code};

    pljit::PLjit pljit;

    auto handle = pljit.registerFunction(valid_source);

    auto result = handle.execute({1});

    if (result.index() == 0) {
        std::cout << std::get<0>(result) << std::endl;
    } else {
        std::get<1>(result).print();
    }

    return 0;
}
//---------------------------------------------------------------------------
