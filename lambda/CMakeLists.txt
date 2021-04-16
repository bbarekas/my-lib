# CMake for lambdas.

cmake_minimum_required(VERSION 2.8.0)

project (lambdas)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(lambdas lambdas.cpp)
