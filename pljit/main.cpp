#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <iostream>

//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
int main() {
    SourceCode code("hello");
    Lexer lexer(code);

    cout << "use for experiments" << endl;
}
//---------------------------------------------------------------------------
