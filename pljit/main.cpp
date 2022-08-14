#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main() {
    SourceCode code("hello");
    Lexer lexer(code);
    size_t l;
    int64_t i {std::stoll("12n", &l)};

    std::cout << "use for experiments" << std::endl;
}
//---------------------------------------------------------------------------
