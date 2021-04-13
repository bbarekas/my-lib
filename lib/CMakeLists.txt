# CMake

cmake_minimum_required(VERSION 2.8.0)

project (hello)

set(CMAKE_VERBOSE_MAKEFILE ON)
#option (BUILD_TESTS "Build test projects." ON)

#Generate the shared library from the sources
file(GLOB MYSOURCES "src/*.c")
add_library(mylib SHARED ${MYSOURCES})

add_executable(hello hello.cpp)

add_subdirectory (examples)

#if (${BUILD_TESTS})
add_subdirectory (tests)
# endif ()


install(TARGETS mylib DESTINATION /usr/lib)
