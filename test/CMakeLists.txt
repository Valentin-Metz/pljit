set(TEST_SOURCES
        # add your source files here
        Tester.cpp
        Lexer.cpp)

add_executable(tester ${TEST_SOURCES})
target_link_libraries(tester PUBLIC
        pljit_core
        GTest::GTest)

target_include_directories(tester PRIVATE ../pljit)
