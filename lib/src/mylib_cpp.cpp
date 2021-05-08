/**
 * mylib_cpp.cpp
 *
 * Created by bbarekas on 20-Apr-21.
 *
 **/

#include <iostream>
#include <string>
#include <map>

#include "../include/mylib.h"

using namespace std;


//std::map<long long, void *> mListenerMap;
std::map<long long, void *> mListenerMap;


/**
 * Function with classic callback argument
 * void (*callback_t) (int n)
 *
 * @param repeat
 * @param cb
 */
void mylib_old_callback_cpp(int repeat, callback_t cb) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    if (repeat == 0) {
        auto pointer2 = &cb;
        auto longara = reinterpret_cast<long long>(pointer2);

        //printf(" > mListenerMap: size: %ld \n", mListenerMap.size());
        //printf(" > > Insert: %lld %p \n", longara, pointer2);

        //mListenerMap.insert(std::pair<long long, void *>(longara, pointer2));
    }

    for (int i = 0; i < repeat; i++) {
        int value = mylib_rand();
        cb(value);
    }

    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(uint32_t)>
 *
 * @param repeat
 * @param cb
 */
void mylib_int_callback_cpp(int repeat, int_callback_cpp_t cb) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    if (repeat == 0) {
        //auto pointer = static_cast<void *>(cb);

        //callback_cpp_t pointer = reinterpret_cast<callback_cpp_t>(cb);


        //void * pointer = static_cast<void *>(cb);
        //auto long_func = reinterpret_cast<long long>(pointer);

        //printf(" > Register - int: [%ld]  ll: %lld  p: %p \n", mListenerMap.size(), long_func, pointer);

        //int_callback_cpp_t *fp = static_cast<int_callback_cpp_t *>(pointer);
        //(*fp)(1);

        //mListenerMap.insert(std::pair<long long, void *>(long_func, pointer));
    }

    for (int i = 0; i < repeat; i++) {
        int value = mylib_rand();
        (cb)(value);
    }

    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(bool)>
 *
 * @param repeat
 * @param cb
 */
void mylib_bool_callback_cpp(int repeat, bool_callback_cpp_t cb) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    /*
    if (repeat == 0) {
        auto pointer = reinterpret_cast<long long>(cb);
        void *vPtr = reinterpret_cast<void *>(cb);

        printf(" > mListenerMap: size: %d \n", mListenerMap.size());
        printf(" > > Insert: %p %p: %d \n", pointer, vPtr);

        mListenerMap.insert(std::pair<long long, void *>(pointer, vPtr));
    }
    */

    for (int i = 0; i < repeat; i++) {
        bool odd = mylib_rand()%2;
        cb(odd);
    }
    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(char *)>
 *
 * @param repeat
 * @param cb
 */
void mylib_string_callback_cpp(int repeat, string_callback_cpp_t cb) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    /*
    if (repeat == 0) {
        auto pointer = reinterpret_cast<long long>(cb);
        void *vPtr = reinterpret_cast<void *>(cb);

        printf(" > mListenerMap: size: %d \n", mListenerMap.size());
        printf(" > > Insert: %p %p: %d \n", pointer, vPtr);

        mListenerMap.insert(std::pair<long long, void *>(pointer, vPtr));
    }
    */

    for (int i = 0; i < repeat; i++) {
        cb(std::to_string(mylib_rand()).c_str());
    }
    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function with std::function callback argument
 * std::function<void(std::vector<const char *>)>
 *
 * @param repeat
 * @param cb
 */
void mylib_vector_callback_cpp(int repeat, vector_callback_cpp_t cb) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    if (repeat == 0) {
    /*
        auto pointer = reinterpret_cast<long long>(cb);
        void *vPtr = reinterpret_cast<void *>(cb);

        printf(" > mListenerMap: size: %d \n", mListenerMap.size());
        printf(" > > Insert: %p %p: %d \n", pointer, vPtr);

        mListenerMap.insert(std::pair<long long, void *>(pointer, vPtr));
        */
    }
    else {
        std::vector<const char *> v;

        v.push_back("one");
        v.push_back("two");
        v.push_back("three");

        for (int i = 0; i < repeat; i++) {
            cb(v);
        }
    }

    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}

/**
 * Function that call all callbacks registered into mListenerMap
 *
 * @param repeat
 */
void mylib_int_callback_run_cpp(int repeat) {
    printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    printf(" > mListenerMap: size: %ld \n", mListenerMap.size());

    for (int i = 0; i < repeat; i++) {

        printf(" > Repeat: %d \n", i);

        // Iterate over the map using c++11 range based for loop
        for (std::pair<long long, void *> element : mListenerMap) {
            long long p = element.first;
            void * pointer = element.second;

            printf(" > > element: %lld %p \n", p, pointer);
            printf(" > Executing - int: [%ld]  ll: %lld  p: %p \n", mListenerMap.size(), p, pointer);

            int_callback_cpp_t *cb = static_cast<int_callback_cpp_t *>(pointer);

            int value = mylib_rand();
            (*cb)(value);
        }

    }

    printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}
