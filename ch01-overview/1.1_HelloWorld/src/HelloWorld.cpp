/**
 * File: HelloWorld.cpp
 * --------------------
 * This file is adapted from the example on page 1 of Kernighan and Ritchie's
 * book The C Programming Language.
 */

#include <iostream>
#include "console.h"  // redirect the output to Java console

using namespace std;

int main() {
    cout << "hello, world" << endl;
    cout << __cplusplus << endl;
    return 0;
}
