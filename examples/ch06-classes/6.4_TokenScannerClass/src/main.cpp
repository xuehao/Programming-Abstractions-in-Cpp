/**
 * File: main.cpp
 * --------------
 * Using the TokenScanner class
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "tokenscanner_class.h"

using namespace std;

int main() {
    MyTokenScanner scanner;
    Map<string, int> wordCounts;

    ifstream infile;
    promptUserForFile(infile, "Input file(e.g. Macbeth.txt): ");

    Vector<string> lines;
    readEntireFile(infile, lines);
    for (const string& line : lines) {
        scanner.setInput(line);
        while (scanner.hasMoreTokens()) {
            string word = scanner.nextToken();
            wordCounts[toLowerCase(word)]++;
        }
    }
    infile.close();

    for (const string& word : wordCounts) {
        cout << left << setw(15) << word << right << setw(5) << wordCounts[word] << endl;
    }

    return 0;
}
