add_subdirectory(source_code_management)
add_subdirectory(error_management)
add_subdirectory(lexer)
add_subdirectory(parse_tree)
add_subdirectory(ast)

add_library(pljit_core PLjit.cpp FunctionHandle.cpp FunctionHandle.hpp FunctionStorage.cpp FunctionStorage.hpp)

target_link_libraries(pljit_core source_code_management error_management lexer parse_tree ast)
