add_subdirectory(source_code_management)
add_subdirectory(pljit_core_utility)
add_subdirectory(lexer)
add_subdirectory(tokens)

add_library(pljit_core pljit_core.cpp)

target_link_libraries(pljit_core lexer pljit_core_utility)
