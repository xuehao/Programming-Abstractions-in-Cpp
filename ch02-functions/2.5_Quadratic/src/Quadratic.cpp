/*
 * File: Quadratic.cpp
 * -------------------
 * This program finds roots of the quadratic equation
 *
 * a * x^2 + b * x + c = 0
 *
 * If a is 0 or if the equation has no real roots, the
 * program prints an error message and exits.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include "console.h"
using namespace std;

/* Function prototypes */
void getCoefficients(double& a, double& b, double& c);
void solveQuadratic(double a, double b, double c, double& x1, double& x2);
void printRoots(double x1, double x2);
void error(string msg);

/* Main program */
int main() {
    double a, b, c, r1, r2;
    getCoefficients(a, b, c);
    solveQuadratic(a, b, c, r1, r2);
    printRoots(r1, r2);
    return 0;
}

/*
 * Function: getCoefficients
 * Usage: getCoefficients(a, b, c);
 * --------------------------------
 * Reads in the coefficients of a quadratic equation into the
 * reference parameters a, b, and c.
 */
void getCoefficients(double& a, double& b, double& c) {
    cout << "Enter coefficients for the quadratic equation:" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
}

/*
 * Function: solveQuadratic
 * Usage: solveQuadratic(a, b, c, x1, x2);
 * ---------------------------------------
 * Solves a quadratic equation for the coefficients a, b, and c. The
 * roots are returned in the reference parameters x1 and x2.
 */
void solveQuadratic(double a, double b, double c, double& x1, double& x2) {
    if (a == 0)
        error("The coefficient a must be nonzero.");
    double disc = b * b - 4 * a * c;
    if (disc < 0)
        error("This equation has no real roots.");
    double sqrtDisc = sqrt(disc);
    x1 = (-b + sqrtDisc) / (2 * a);
    x2 = (-b - sqrtDisc) / (2 * a);
}

/*
 * Function: printRoots
 * Usage: printRoots(x1, x2);
 * --------------------------
 * Displays x1 and x2, which are the roots of the quadratic equation.
 */
void printRoots(double x1, double x2) {
    if (x1 == x2) {
        cout << "There is a double root at " << x1 << endl;
    } else {
        cout << "The roots are " << x1 << " and " << x2 << endl;
    }
}

/*
 * Function: error
 * Usage: error(msg);
 * ------------------
 * Writes the string msg to the cerr stream and then exits the program
 * with a standard status value indicating that a failure has occurred.
 */
void error(string msg) {
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
