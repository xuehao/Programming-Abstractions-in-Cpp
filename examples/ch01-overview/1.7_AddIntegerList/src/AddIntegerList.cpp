/*
 * File: AddIntegerList.cpp
 * ------------------------
 * This program adds a list of integers. The end of the
 * input is indicated by entering a sentinel value, which
 * is defined by setting the value of the constant SENTINEL.
 */

#include <iostream>
#include "console.h"
using namespace std;

/*
 * Constant: SENTINEL
 * ------------------
 * This constant defines the value used to terminate the input
 * list and should therefore not be a value one would want to
 * include as a data value. The value 0 therefore makes sense
 * for a program that adds a series of numbers because the
 * user can simply skip any 0 values in the input.
 */
const int SENTINEL = 0;

/* Main program */
int main() {
    cout << "This program adds a list of numbers." << endl;
    cout << "Use " << SENTINEL << " to signal the end." << endl;
    int total = 0;
    while (true) {
        int value;
        cout << " ? ";
        cin >> value;
        if (value == SENTINEL)
            break;
        total += value;
    }
    cout << "The total is " << total << endl;
    return 0;
}
