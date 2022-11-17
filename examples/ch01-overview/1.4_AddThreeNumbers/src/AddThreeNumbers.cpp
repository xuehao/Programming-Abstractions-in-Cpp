/*
 * File: AddThreeNumbers.cpp
 * -------------------------
 * This program adds three floating-point numbers and prints their sum.
 */

#include <iostream>
#include "console.h"
using namespace std;

int main() {
    double n1, n2, n3;
    cout << "This program adds three numbers." << endl;
    cout << "1st number: ";
    cin >> n1;
    cout << "2nd number: ";
    cin >> n2;
    cout << "3rd number: ";
    cin >> n3;
    double sum = n1 + n2 + n3;
    cout << "The sum is " << sum << endl;
    return 0;
}
