#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main() {
    SourceCode code("hello");
    Lexer lexer(code);

    std::cout << "use for experiments" << std::endl;
}
//---------------------------------------------------------------------------
