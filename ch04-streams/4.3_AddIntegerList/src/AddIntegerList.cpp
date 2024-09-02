/**
 * File: AddIntegerList.cpp
 * ------------------------
 * This program adds a list of integers. The end of the
 * input is indicated by entering a sentinel value, which
 * is defined by setting the value of the constant SENTINEL.
 */

#include <iostream>
#include "console.h"
#include "filelib.h"
using namespace std;

/* Main program */

int main() {
    ifstream infile;
    promptUserForFile(infile, "Input file(e.g. data.txt): ");
    int total = 0;
    string line;
    while (getline(infile, line)) {
        total += stringToInteger(line);
    }
    infile.close();
    cout << "The sum is " << total << endl;
    return 0;
}
