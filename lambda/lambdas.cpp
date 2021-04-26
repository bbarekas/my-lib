/**
 * lamdas.cpp
 *
 * Created by bbarekas on 14-Apr-21.
 *
 **/

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <functional> // for std::greater


static bool containsNut(std::string_view str) // static means internal linkage in this context
{
    //std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    // std::string_view::find returns std::string_view::npos, which is a very large number,
    // if it doesn't find the substring.
    // Otherwise it returns the index where the substring occurs in str.

    //std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return (str.find("nut") != std::string_view::npos);
}

int caseNoLambda() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    constexpr
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    // std::find_if takes a pointer to a function
    const auto found{std::find_if(arr.begin(), arr.end(), containsNut)};

    if (found == arr.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

int caseLambda() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    constexpr
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    // Define the function right where we use it.
    const auto found{std::find_if(arr.begin(), arr.end(),
                                  [](std::string_view str) -> bool// here's our lambda, no capture clause
                                  {
                                      return (str.find("nut") != std::string_view::npos);
                                  })};

    if (found == arr.end()) {
        std::cout << "No nuts\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

int caseLambdaLocal() {
    std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "lemon"};

    // Ask the user what to search for.
    std::cout << "search for: ";

    std::string search{"na"};
    //std::cin >> search;

    auto found{std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
        // Search for @search rather than "nut".
        return (str.find(search) != std::string_view::npos); // Error: search not accessible in this scope
    })};

    if (found == arr.end()) {
        std::cout << "Not found\n";
    } else {
        std::cout << "Found " << *found << '\n';
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}


int caseLambdaMutable() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    int ammo{10};

    // Define a lambda and store it in a variable called "shoot".
    auto shoot =
            [ammo]() mutable {
                --ammo;
                std::cout << "Pew! " << ammo << " shot(s) left.\n";
            };

    // Call the lambda
    shoot();

    std::cout << ammo << " shot(s) left\n";

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

struct Car {
    std::string make{};
    std::string model{};
};


int caseLambdaReference() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    std::array<Car, 3> cars{{{"Volkswagen", "Golf"},
                                    {"Toyota", "Corolla"},
                                    {"Honda", "Civic"}}};

    int comparisons{0};

    auto comparison = [&comparisons](const auto &a, const auto &b) {
        // We captured comparisons by reference. We can modify it without "mutable".
        ++comparisons;
        // Sort the cars by their make.
        return (a.make < b.make);
    };

    std::sort(cars.begin(), cars.end(), comparison);

    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto &car : cars) {
        std::cout << car.make << ' ' << car.model << '\n';
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

int caseLambdaDefaultValue() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    std::array areas{100, 25, 121, 40, 56};

    int width{10};
    int height{10};

    //std::cout << "Enter width and height: ";
    //std::cin >> width >> height;

    auto found{std::find_if(areas.begin(), areas.end(),
                            [=](int knownArea) { // will default capture width and height by value
                                return (width * height == knownArea); // because they're mentioned here
                            })};

    if (found == areas.end()) {
        std::cout << "I don't know this area :(\n";
    } else {
        std::cout << "Area found :)\n";
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

int caseLambdaVariable() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    std::array areas{100, 25, 121, 40, 56};

    int width{10};
    int height{10};

    //std::cout << "Enter width and height: ";
    //std::cin >> width >> height;

    // We store areas, but the user entered width and height.
    // We need to calculate the area before we can search for it.
    auto found{std::find_if(areas.begin(), areas.end(),
            // Declare a new variable that's visible only to the lambda.
            // The type of userArea is automatically deduced to int.
                            [userArea{width * height}](int knownArea) {
                                return (userArea == knownArea);
                            })};

    if (found == areas.end()) {
        std::cout << "I don't know this area :(\n";
    } else {
        std::cout << "Area found :)\n";
    }

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
    return 0;
}

// returns a lambda
auto makeWalrus(const std::string& name)
{
    // Capture name by reference and return the lambda.
    return [&]() {
        std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
    };
}

int caseLambdaUndefined()
{
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    // Create a new walrus whose name is Roofus.
    // sayName is the lambda returned by makeWalrus.
    auto sayName{ makeWalrus("Roofus") };

    // Call the lambda function that makeWalrus returned.
    sayName();

    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);
    return 0;
}

int caseLambdaCopy()
{
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    int i{ 0 };

    // Create a new lambda named count
    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };

    count(); // invoke count

    auto otherCount{ count }; // create a copy of count

    // invoke both count and the copy
    count();
    otherCount();

    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);
    return 0;
}

void invoke(const std::function<void(void)>& fn)
{
    fn();
}

int caseLambdaInvoke()
{
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
        std::cout << ++i << '\n';
    } };


    //count();
    //count();
    //count();

    invoke(count);
    invoke(count);
    invoke(count);

    std::cout << "Invoke using std::ref" << '\n';

    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));

    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);
    return 0;
}

int main() {
    std::printf("[TRACE] <ENTRY> Called function: %s \n", __FUNCTION__);

    []() {}; // defines a lambda with no captures, no parameters, and no return type

    // caseNoLambda
    std::cout << "Calling caseNoLambda()" << '\n';
    caseNoLambda();

    // caseLambda
    std::cout << "Calling caseLambda()" << '\n';
    caseLambda();

    // caseLambdaLocal
    std::cout << "Calling caseLambdaLocal()" << '\n';
    caseLambdaLocal();

    // caseLambdaMutable
    std::cout << "Calling caseLambdaMutable()" << '\n';
    caseLambdaMutable();

    // caseLambdaReference
    std::cout << "Calling caseLambdaReference()" << '\n';
    caseLambdaReference();

    // caseLambdaDefaultValue
    std::cout << "Calling caseLambdaDefaultValue()" << '\n';
    caseLambdaDefaultValue();

    // caseLambdaVariable
    std::cout << "Calling caseLambdaVariable()" << '\n';
    caseLambdaVariable();

    // caseLambdaUndefined
    std::cout << "Calling caseLambdaUndefined()" << '\n';
    caseLambdaUndefined();

    // caseLambdaCopy
    std::cout << "Calling caseLambdaCopy()" << '\n';
    caseLambdaCopy();


    // caseLambdaInvoke
    std::cout << "Calling caseLambdaInvoke()" << '\n';
    caseLambdaInvoke();


    /*
    std::cout << '\n' << " * EXAMPLES *" << '\n';

    // A regular function pointer. Only works with an empty capture clause.
    double (*addNumbers1)(double, double){
            [](double a, double b) {
                return (a + b);
            }
    };

    //std::cout << typeid(addNumbers1).name() << std::endl;
    std::cout << "Calling addNumbers1(1, 2) " << addNumbers1(1, 2) << '\n';

    // Using std::function. The lambda could have a non-empty capture clause (Next lesson).
    std::function addNumbers2{ // note: pre-C++17, use std::function<double(double, double)> instead
            [](double a, double b) {
                return (a + b);
            }
    };

    //std::cout << typeid(addNumbers2).name() << std::endl;
    std::cout << "Calling addNumbers2(1, 2) " << addNumbers2(1, 2) << '\n';

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3{
            [](double a, double b) {
                return (a + b);
            }
    };

    //std::cout << typeid(addNumbers3).name() << std::endl;
    std::cout << "Calling addNumbers3(1, 2) " << addNumbers3(1, 2) << '\n';

    constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
    };

    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                              [](const auto& a, const auto& b) {
                                                  return (a[0] == b[0]);
                                              }) };

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
        // std::next returns the next iterator after sameLetter
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                  << " start with the same letter\n";
    }

    // Count how many months consist of 5 letters
    const auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                               [](std::string_view str) {
                                                   return (str.length() == 5);
                                               }) };

    std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";
*/
    /*
    // Print a value and count how many times @print has been called.
    auto print{
            [](auto value) {
                static int callCount{ 0 };
                std::cout << callCount++ << ": " << value << '\n';
            }
    };

    print("hello"); // 0: hello
    print("world"); // 1: world

    print(1); // 0: 1
    print(2); // 1: 2

    print("ding dong"); // 2: ding dong
    print(5); // 1: 2
    */

    /*
    auto divide{ [](int x, int y, bool bInteger) -> double { // note: no specified return type
        if (bInteger)
            return x / y;
        else
            return static_cast<double>(x) / y; // ERROR: return type doesn't match previous return type
    } };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';

    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass std::greater to std::sort
    std::sort(arr.begin(), arr.end(), std::greater{}); // note: need curly braces to instantiate object

    for (int i : arr)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
    */

    std::printf("[TRACE] <EXIT> Called function: %s \n", __FUNCTION__);
}