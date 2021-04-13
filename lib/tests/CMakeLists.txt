
include(CTest)

enable_testing ()

include_directories(../include)

add_executable(simple_test simple_test.c)
target_link_libraries(simple_test mylib)
add_test (simple_test simple_test)

add_executable(simple_test_cpp simple_test.cpp)
target_link_libraries(simple_test_cpp mylib)
add_test (simple_test_cpp simple_test_cpp)
