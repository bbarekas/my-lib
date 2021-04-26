/**
 * mylib_cpp.cpp
 *
 * Created by bbarekas on 20-Apr-21.
 *
 **/

#include <iostream>
#include <string>

#include "../include/mylib.h"

/**
 * Function with std::function callback argument
 * std::function<void(uint32_t)>
 *
 * @param repeat
 * @param cb
 */
void mylib_int_callback_cpp(int repeat, int_callback_cpp_t cb) {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    for (int i = 0; i < repeat; i++) {
        cb(i);
    }
    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(bool)>
 *
 * @param repeat
 * @param cb
 */
void mylib_bool_callback_cpp(int repeat, bool_callback_cpp_t cb) {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    for (int i = 0; i < repeat; i++) {
        bool odd = mylib_rand()%2;
        cb(odd);
    }
    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(char *)>
 *
 * @param repeat
 * @param cb
 */
void mylib_string_callback_cpp(int repeat, string_callback_cpp_t cb) {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    for (int i = 0; i < repeat; i++) {
        cb(std::to_string(mylib_rand()).c_str());
    }
    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}
