#ifndef PLJIT_RUNTIMEERROR_HPP
#define PLJIT_RUNTIMEERROR_HPP

#include "Error.hpp"
#include <string>
class RuntimeError : public pljit::Error{
    public:
    const std::string error_message;

    explicit RuntimeError(std::string error_message);
};

#endif //PLJIT_RUNTIMEERROR_HPP
