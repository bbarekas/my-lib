/**
 * mylib.h
 *
 * Created by bbarekas on 10-Apr-21.
 *
 **/

#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
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
