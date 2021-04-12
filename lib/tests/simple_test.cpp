/**
 * simple_test.c
 *
 * Created by bbarekas on 11-Apr-21.
 *
 **/

#include <iostream>
using namespace std;

#include "mylib.h"

#define MAX 10

int a[MAX];

int main() {
    int i;

    /* fill array */
    for (i = 0; i < MAX; i++) {
        a[i] = mylib_rand();
        //printf("%d\n", a[i]);
        std::cout << a[i] << std::endl;

    }

    mylib_sort(MAX, a);

    /* print sorted array */
    //printf("--------------------\n");
    std::cout << "--------------------\n" << std::endl;

    for (i = 0; i < MAX; i++)
        //printf("%d\n", a[i]);
        std::cout << a[i] << std::endl;

    return 0;
}
