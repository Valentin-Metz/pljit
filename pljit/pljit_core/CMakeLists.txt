set(PLJIT_SOURCES
        execution/PLjit.cpp
        include/PLjit.hpp
        execution/PLjit_FunctionHandle.cpp
        include/PLjit_FunctionHandle.hpp
        execution/FunctionStorage.cpp
        execution/FunctionStorage.hpp)

add_subdirectory(source_code_management)
add_subdirectory(error_management)
add_subdirectory(lexer)
add_subdirectory(parse_tree)
add_subdirectory(ast)

add_library(pljit_core ${PLJIT_SOURCES})

target_link_libraries(pljit_core source_code_management error_management lexer parse_tree ast)

target_include_directories(pljit_core PRIVATE .)
target_include_directories(source_code_management PRIVATE .)
target_include_directories(error_management PRIVATE .)
target_include_directories(lexer PRIVATE .)
target_include_directories(parse_tree PRIVATE .)
target_include_directories(ast PRIVATE .)
