#include "pljit_core/lexer/Lexer.hpp"
#include "pljit_core/source_code_management/SourceCode.hpp"
#include <iostream>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main() {
    std::string valid_source_code = "PARAM width, height, depth;\n"
                                    "VAR volume;\n"
                                    "CONST density = 2400;\n\n"
                                    "BEGIN\n"
                                    "volume := width * height * depth;\n"
                                    "RETURN density * volume\n"
                                    "END.";

    SourceCode c{SourceCode(valid_source_code)};
    Lexer l{c};

    std::cout << "success" << std::endl;
}
//---------------------------------------------------------------------------
