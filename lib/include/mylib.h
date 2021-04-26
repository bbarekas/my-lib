/**
 * mylib.h
 *
 * Created by bbarekas on 10-Apr-21.
 *
 **/

#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
#include <functional> // std::function container

// Callback types.

// Callback C++ function with int.
typedef std::function<void(uint32_t)> int_callback_cpp_t;

// Callback C++ function with bool.
typedef std::function<void(bool)> bool_callback_cpp_t;

// Callback C++ function with string.
typedef std::function<void(const char *)> string_callback_cpp_t;


// Callback registers.

// mylib_callback_cpp
extern void mylib_int_callback_cpp(int repeat, int_callback_cpp_t cb);

// mylib_bool_callback_cpp
extern void mylib_bool_callback_cpp(int repeat, bool_callback_cpp_t cb);

// mylib_string_callback_cpp
extern void mylib_string_callback_cpp(int repeat, string_callback_cpp_t cb);


extern "C" {
#endif

// Callback function without context pointer
typedef void (*callback_t) (int n);

// Callback function with context pointer
typedef void (*callback_closure_t) (int n, void* data);

// mylib_callback
extern void mylib_callback(int size, callback_t fun);

// mylib_callback_withdata
extern void mylib_callback_withdata(int size, callback_closure_t fun, void *data) ;

// mylib_rand:
extern int mylib_rand();

// mylib_sort:
extern void mylib_sort(int, int []);

#ifdef __cplusplus
}
#endif

#endif // MYLIB_H
