/**
 * simple_test.c
 *
 * Created by bbarekas on 11-Apr-21.
 *
 **/

#include <iostream>
#include <string>
using namespace std;

#include "mylib.h"


/**
 * Classic callback of type int_callback_cpp_t.
 * @param n
 */
void int_callback1(uint32_t n) {
    printf(" > [Function int] n = %d \n", n);
}

/**
 * Classic callback of type bool_callback_cpp_t.
 * @param b
 */
void bool_callback1(bool b) {
    printf(" > [Function bool] b = %s \n", b ? "true":"false");
}

/**
 * Classic callback of type string_callback_cpp_t.
 * @param s
 */
void string_callback1(const char * s) {
    printf(" > [Function string] s = %s \n", s);

}

/**
 * Classic callback of type vector_callback_cpp_t.
 * @param v
 */
void vector_callback1(std::vector<const char *> v) {
    printf(" > [Function vector] v = ");
    for (const auto& s: v)
        printf("%s ", s);
    printf("\n");
}


/**
 * test_int_callback
 * Check mylib_int_callback_cpp
 */
void test_int_callback() {

    // Classic Function/
    mylib_int_callback_cpp(2, int_callback1);

    // Non-capturing lambda.
    mylib_int_callback_cpp(2, [](int n){
        printf(" > [Lambda int 1] n = %d \n", n);
    });

    // Capturing lambda.
    string text = "Home";
    mylib_int_callback_cpp(2, [=](int n){
        printf(" > [Lambda int 2] %s = %d \n", text.c_str(), n);
    });
    printf(" Text: %s\n", text.c_str());

    // Mutating lambda.
    mylib_int_callback_cpp(2, [&text](int n){
        printf(" > [Lambda int 3] %s = %d \n", text.c_str(), n);
        text = text + to_string(n);
    });
    printf(" Text: %s\n", text.c_str());

}

/**
 * test_bool_callback
 * Check mylib_bool_callback_cpp
 */
void test_bool_callback() {

    // Classic Function.
    mylib_bool_callback_cpp(2, bool_callback1);

    // Non-capturing lambda.
    mylib_bool_callback_cpp(2, [](bool b){
        printf(" > [Lambda bool 1] b = %s \n", b ? "true":"false");
    });

    // Mutating lambda.
    string text = "Home";
    mylib_bool_callback_cpp(2, [&text](bool b){
        printf(" > [Lambda bool 2] b = %s \n", b ? "true":"false");
        text = text + to_string(b);
    });
    printf(" Text: %s\n", text.c_str());

}

/**
 * test_string_callback
 * Check mylib_string_callback_cpp
 */
void test_string_callback() {

    // Classic Function.
    mylib_string_callback_cpp(2, string_callback1);

    // Non-capturing lambda.
    mylib_string_callback_cpp(2, [](const char * s){
        printf(" > [Lambda string 1] s = %s \n", s);
    });

    // Mutating lambda.
    string text = "Home";
    mylib_string_callback_cpp(2, [&text](const char * s){
        printf(" > [Lambda string 2] %s = %s \n", text.c_str(), s);
        text = text + s;
    });
    printf(" Text: %s\n", text.c_str());
}

/**
 * test_vector_callback
 * Check mylib_vector_callback_cpp
 */
void test_vector_callback() {

    // Classic Function.
    mylib_vector_callback_cpp(2, vector_callback1);

    // Non-capturing lambda.
    mylib_vector_callback_cpp(2, [](std::vector<const char *> v){
        printf(" > [Lambda vector 1] v = ");
        for (const auto& s: v)
            printf("%s ", s);
        printf("\n");
    });

    // Mutating lambda.
    string text = "Home";
    mylib_vector_callback_cpp(2, [&text](std::vector<const char *> v){
        v.push_back(text.c_str());
        printf(" > [Lambda vector 1] v = ");
        for (const auto& s: v)
            printf("%s ", s);
        printf("\n");
    });

}


/**
 * Entry
 * @return
 */
int main() {

    // Check mylib_int_callback_cpp
    test_int_callback();

    // Check mylib_bool_callback_cpp
    test_bool_callback();

    // Check mylib_string_callback_cpp
    test_string_callback();

    // Check mylib_vector_callback_cpp
    test_vector_callback();

    return 0;
}
