#ifndef PLJIT_LEXERARITHMETICTOKEN_HPP
#define PLJIT_LEXERARITHMETICTOKEN_HPP

#include "LexerToken.hpp"
class LexerArithmeticToken : public LexerToken {
    public:
    enum ArithmeticOperator {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
    };
    const ArithmeticOperator arithmetic_operator_type;
    LexerArithmeticToken(SourceCodeReference source_code_reference, ArithmeticOperator arithmetic_operator) : LexerToken(source_code_reference, Arithmetic), arithmetic_operator_type(arithmetic_operator) {}
};

#endif //PLJIT_LEXERARITHMETICTOKEN_HPP
