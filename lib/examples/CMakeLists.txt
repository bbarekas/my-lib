# CMake for examples.

include_directories(../include)

add_executable(c_example c_example.c)
target_link_libraries(c_example mylib)

add_executable(cpp_example cpp_example.cpp)
target_link_libraries(cpp_example mylib)
