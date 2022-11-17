/*
 * File: PrecisionExample.cpp
 * --------------------------
 * This program demonstrates various options for floating-point output
 * by displaying three different constants (pi, the speed of light in
 * meters/second, and the fine-structure constant). These constants
 * are chosen because they illustrate a range of exponent scales.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include "console.h"
using namespace std;

/* Constants */
const double PI = 3.14159265358979323846;
const double SPEED_OF_LIGHT = 2.99792458E+8;
const double FINE_STRUCTURE = 7.2573525E-3;

/* Function prototypes */
void printPrecisionTable();

/* Main program */
int main() {
    cout << uppercase << right;
    cout << "Default format:" << endl << endl;
    printPrecisionTable();
    cout << endl << "Fixed format:" << fixed << endl << endl;
    printPrecisionTable();
    cout << endl << "Scientific format:" << scientific << endl << endl;
    printPrecisionTable();
    return 0;
}

/*
 * Function: printPrecisionTable
 * -----------------------------
 * Generates a simple precision table for the current cout settings.
 */
void printPrecisionTable() {
    cout << " prec |      pi      |  speed of light  | fine-structure" << endl;
    cout << "------+--------------+------------------+----------------" << endl;
    for (int prec = 0; prec <= 6; prec += 2) {
        cout << setw(5) << prec << " |";
        cout << " " << setw(12) << setprecision(prec) << PI << " |";
        cout << " " << setw(16) << setprecision(prec) << SPEED_OF_LIGHT << " |";
        cout << " " << setw(14) << setprecision(prec) << FINE_STRUCTURE << endl;
    }
}
