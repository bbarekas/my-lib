/**
 * simple_test.c
 *
 * Created by bbarekas on 10-Apr-21.
 *
 **/

#include <stdio.h>
#include "mylib.h"

#define MAX 10

int a[MAX];

void main() {
    int i;

    /* fill array */
    for (i = 0; i < MAX; i++) {
        a[i] = mylib_rand();
        printf("%d\n", a[i]);
    }

    mylib_sort(MAX, a);

    /* print sorted array */
    printf("--------------------\n");
    for (i = 0; i < MAX; i++)
        printf("%d\n", a[i]);
}
