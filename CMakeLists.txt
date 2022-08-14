cmake_minimum_required(VERSION 3.22)
project(pljit CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Infrastructure)

add_subdirectory(pljit)
add_subdirectory(test)
