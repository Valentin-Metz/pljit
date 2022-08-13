#ifndef FINAL_SOURCE_CODE_H
#define FINAL_SOURCE_CODE_H

#include "../pljit_core_utility/NonCopyable.h"
#include <string>
#include <utility>

class SourceCode : public NonCopyable {
    std::string source_code;

    public:
    explicit SourceCode(std::string source_code) : source_code(std::move(source_code)) {}
};

#endif //FINAL_SOURCE_CODE_H
