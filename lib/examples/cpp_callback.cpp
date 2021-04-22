/**
 * simple_test.c
 *
 * Created by bbarekas on 11-Apr-21.
 *
 **/

#include <iostream>
#include<string>
using namespace std;

#include "mylib.h"

int main() {

    /** Non-capturing lambdas. */
    mylib_callback_cpp(5, [](int n){
        std::printf(" [Lambda 1] n = %d \n", n);
    });

    /** Capturing lambdas. */
    std::string text = "Home";
    mylib_callback_cpp(5, [=](int n){
        std::printf(" [Lambda 2] %s = %d \n", text.c_str(), n);
    });
    std::printf(" Text: %s\n", text.c_str());

    /** Mutating lambdas. */
    mylib_callback_cpp(5, [&text](int n){
        std::printf(" [Lambda 2] %s = %d \n", text.c_str(), n);
        text = text + std::to_string(n);
    });

    std::printf(" Text: %s\n", text.c_str());


    return 0;
}
