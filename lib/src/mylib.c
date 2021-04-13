/**
 * mylib.c
 *
 * Created by bbarekas on 10-Apr-21.
 *
 **/

#include <stdio.h>
#include "../include/mylib.h"

int rand_seed = 10;

/**
 * Function with C-callback argument without context pointer.
 *
 * @param size
 * @param fun
 */
void mylib_callback(int size, callback_t fun) {
    printf(" [TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);
    for (int i = 0; i < size; i++) {
        fun(i);
    }
    printf(" [TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with C-callback argument with data pointer for passing function state to
 * to the function pointer.
 *
 * @param size
 * @param fun
 * @param data
 */
void mylib_callback_withdata(int size, callback_closure_t fun, void *data) {
    printf(" [TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);
    for (int i = 0; i < size; i++) {
        fun(i, data);
    }
    printf(" [TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Produces a random number between 0 and 32767.
 *
 * @return
 */
int mylib_rand() {
    rand_seed = rand_seed * 1103515245 + 12345;
    return (unsigned int) (rand_seed / 65536) % 32768;
}

/**
 * Sort an array with bubble sort.
 *
 * @param m
 * @param a
 */
void mylib_sort(int m, int a[]) {
    int x, y, t;
    for (x = 0; x < m - 1; x++)
        for (y = 0; y < m - x - 1; y++)
            if (a[y] > a[y + 1]) {
                t = a[y];
                a[y] = a[y + 1];
                a[y + 1] = t;
            }
}

