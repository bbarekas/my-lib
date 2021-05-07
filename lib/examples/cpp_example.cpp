/**
 * simple_test.c
 *
 * Created by bbarekas on 11-Apr-21.
 *
 **/

#include <iostream>
using namespace std;
#include <iomanip>

#include "mylib.h"
#include "json.hpp"

using json = nlohmann::json;


#define MAX 10

int a[MAX];

int main() {
    int i;

    /* fill array */
    for (i = 0; i < MAX; i++) {
        a[i] = mylib_rand();
        std::cout << a[i] << std::endl;
    }

    mylib_sort(MAX, a);
    /* print sorted array */
    std::cout << "--------------------\n" << std::endl;
    for (i = 0; i < MAX; i++)
        std::cout << a[i] << std::endl;

    // jdEmployees
    json jdEmployees =
            {
                    {"firstName","Sean"},
                    {"lastName","Brown"},
                    {"StudentID",21453},
                    {"Department","Computer Sc."}
            };

    // Access the values
    std::string fName = jdEmployees.value("firstName", "oops");
    std::string lName = jdEmployees.value("lastName", "oops");
    int sID = jdEmployees.value("StudentID", 0);
    std::string dept = jdEmployees.value("Department", "oops");

    // Print the values
    std::cout << "First Name: " << fName << std::endl;
    std::cout << "Last Name: " << lName << std::endl;
    std::cout << "Student ID: " << sID << std::endl;
    std::cout << "Department: " << dept << std::endl;

    // Parse from string
    char  buff[] = R"({"redemption":{"_id":"6093df747203400b62ae5156","status":"IN_PROGRESS","rewardId":"606730a3135c6e445518e8dd","applicationId":"606589d0be4b8e42594e393d","installationId":"6093dd24d98bc60b699a9333","offerId":"606730a3135c6e445518e8db","points":1800,"type":"INAPP","sku":"ONE_COIN","redemptionStrategy":"EXTERNAL","voidAfter":"2021-05-06T12:23:12.001Z"}})";

    // Let's parse and serialize JSON
    json jsonBuff = json::parse(buff);
    auto redemId = jsonBuff["redemption"]["_id"].get<std::string>();

    std::cout << "RedemptionId: " << "rec: " + redemId << std::endl;


    return 0;
}
