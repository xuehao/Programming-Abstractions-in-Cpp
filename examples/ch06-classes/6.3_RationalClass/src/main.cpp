/**
 * File: main.cpp
 * --------------
 * Using the Point class
 */

#include <iomanip>
#include <iostream>
#include "console.h"
#include "rational.h"

using namespace std;

int main() {
    double a = 1.0 / 2.0;
    double b = 1.0 / 3.0;
    double c = 1.0 / 6.0;
    double sum = a + b + c;
    cout << setprecision(16);
    cout << "1/2 + 1/3 + 1/6 = " << sum << endl;  // 0.9999...

    Rational x(1.0, 2.0);
    Rational y(1.0, 3.0);
    Rational z(1.0, 6.0);
    Rational total = x + y + z;
    cout << "1/2 + 1/3 + 1/6 = " << total << endl;  // 1

    return 0;
}
