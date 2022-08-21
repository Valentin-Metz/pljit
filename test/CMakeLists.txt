set(TEST_SOURCES
        Tester.cpp
        Lexer.cpp
        ParseTree.cpp
        AbstractSyntaxTree.cpp
        PLjit.cpp
        )

add_executable(tester ${TEST_SOURCES})
target_link_libraries(tester PUBLIC pljit_core GTest::GTest)

target_include_directories(tester PRIVATE ../pljit/pljit_core)
