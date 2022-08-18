add_subdirectory(source_code_management)
add_subdirectory(pljit_core_utility)
add_subdirectory(lexer)
add_subdirectory(parse_tree)
add_subdirectory(ast)

add_library(pljit_core pljit_core.cpp)

target_link_libraries(pljit_core lexer pljit_core_utility parse_tree ast)
