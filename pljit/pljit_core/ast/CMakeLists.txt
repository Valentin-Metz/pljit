add_library(ast Ast.cpp Ast.hpp)
target_link_libraries(ast parse_tree)