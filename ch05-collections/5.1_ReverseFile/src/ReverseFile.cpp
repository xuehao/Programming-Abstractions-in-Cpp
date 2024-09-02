/**
 * File: ReverseFile.cpp
 * ---------------------
 * This program displays the lines of an input file in reverse order.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "vector.h"
using namespace std;

/* Main program */

int main() {
    ifstream infile;
    Vector<string> lines;
    promptUserForFile(infile, "Input file (e.g. test.txt): ");
    readEntireFile(infile, lines);
    infile.close();
    for (int i = lines.size() - 1; i >= 0; i--) {
        cout << lines[i] << endl;
    }
    return 0;
}
