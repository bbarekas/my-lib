/**
 * simple_test.c
 *
 * Created by bbarekas on 11-Apr-21.
 *
 **/

#include <iostream>
using namespace std;

#include "mylib.h"

int main() {

    /** Non-capturing lambdas. */
    mylib_callback_cpp(5, [](int n){
        std::printf(" [Lambda 1] n = %d \n", n);
    });

    return 0;
}
