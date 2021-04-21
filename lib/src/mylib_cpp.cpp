/**
 * mylib_cpp.cpp
 *
 * Created by bbarekas on 20-Apr-21.
 *
 **/

//#include <stdio.h>
#include <iostream>
#include "../include/mylib.h"

/**
 * Function with std::function callback argument without context pointer.
 *
 * @param size
 * @param fun
 */
void mylib_callback_cpp(int size, callback_cpp_t fun) {
    std::printf(" [TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    for (int i = 0; i < size; i++) {
        fun(i);
    }
    std::printf(" [TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}
