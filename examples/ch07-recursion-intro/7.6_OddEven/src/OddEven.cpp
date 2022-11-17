/**
 * File: OddEven.cpp
 * -----------------
 * This program uses mutual recursion to implement the functions
 * isOdd and isEven for nonnegative numbers.
 */

#include <iostream>
#include "console.h"
using namespace std;

/* Function prototypes */

bool isOdd(unsigned int n);
bool isEven(unsigned int n);

/* Main program */

int main() {
    for (int i = 0; i < 10; i++) {
        cout << i << " is " << (isOdd(i) ? "odd" : "even") << endl;
    }
}

/**
 * Function: isOdd
 * Usage: if (isOdd(n)) . . .
 * --------------------------
 * Returns true if the unsigned number n is odd.  A number is odd
 * if it is not even.
 */

bool isOdd(unsigned int n) {
    return !isEven(n);
}

/**
 * Function: isEven
 * Usage: if (isEven(n)) . . .
 * ---------------------------
 * Returns true if the unsigned number n is even.  A number is even
 * either (1) if it is zero or (2) if its predecessor is odd.
 */

bool isEven(unsigned int n) {
    if (n == 0) {
        return true;
    } else {
        return isOdd(n - 1);
    }
}
