
cmake_minimum_required(VERSION 2.8.0)

project (hello)

#Generate the shared library from the sources
file(GLOB MYSOURCES "src/*.c")
add_library(mylib SHARED ${MYSOURCES})

#set( PROJECT_LINK_LIBS libmylib.so )
#link_directories(~/devel/my-lib/lib/build)

include_directories(include)

add_executable(simple_test test/simple_test.c)
target_link_libraries(simple_test mylib)

add_executable(simple_test_cpp test/simple_test.cpp)
target_link_libraries(simple_test_cpp mylib)


add_executable(hello hello.cpp)

install(TARGETS mylib DESTINATION /usr/lib)
