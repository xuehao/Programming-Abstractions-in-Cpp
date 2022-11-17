/**
 * File: LetterFrequency.cpp
 * -------------------------
 * This program counts the frequency of letters in a data file.
 */

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "vector.h"
using namespace std;

/* Constants */

static const int COLUMNS = 7;

/* Main program */

int main() {
    Vector<int> letterCounts(26);
    ifstream infile;
    promptUserForFile(infile, "Input file (e.g. test.txt): ");
    while (true) {
        int ch = infile.get();
        if (ch == EOF)
            break;
        if (isalpha(ch)) {
            letterCounts[toupper(ch) - 'A']++;
        }
    }
    infile.close();
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        cout << setw(COLUMNS) << letterCounts[ch - 'A'] << " " << ch << endl;
    }
    return 0;
}
