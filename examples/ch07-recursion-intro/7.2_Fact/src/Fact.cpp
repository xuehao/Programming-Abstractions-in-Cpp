/**
 * File: Fact.cpp
 * --------------
 * This file generates a list of factorials.  The test program
 * stops when the value of fact(n) is smaller than its predecessor,
 * which means that an overflow must have occurred.
 */

#include <iostream>
#include "console.h"
using namespace std;

// TODO: Function prototypes
int fact(int n);

/* Main program */

int main() {
    cout << "4! = " << fact(4) << endl;
    return 0;
}

/**
 * Function: fact
 * Usage: int nfact = fact(n);
 * --------------------------------
 * Computes the factorial of n using the following recursive
 * formulation:
 *
 *    fact(0) = 1
 *    fact(n) = n * fact(n - 1)
 */

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
