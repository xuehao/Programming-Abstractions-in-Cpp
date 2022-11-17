/**
 * File: WordFrequency.cpp
 * -----------------------
 * This program computes the frequency of words in a text file.
 */

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

void countWords(istream& stream, Map<string, int>& wordCounts);
void displayWordCounts(Map<string, int>& wordCounts);
void extractWords(string line, Vector<string>& words);

/* Main program */

int main() {
    ifstream infile;
    Map<string, int> wordCounts;
    promptUserForFile(infile, "Input file (e.g. Macbeth.txt): ");
    countWords(infile, wordCounts);
    infile.close();
    displayWordCounts(wordCounts);
    return 0;
}

/**
 * Function: countWords
 * Usage: countWords(stream, wordCounts);
 * --------------------------------------
 * Counts the words in the input stream, storing the results in wordCounts.
 */

void countWords(istream& stream, Map<string, int>& wordCounts) {
    Vector<string> lines, words;
    readEntireFile(stream, lines);
    for (const string& line : lines) {
        extractWords(line, words);
        for (const string& word : words) {
            wordCounts[toLowerCase(word)]++;
        }
    }
}

/**
 * Function: displayWordCounts
 * Usage: displayWordCounts(wordCount);
 * ------------------------------------
 * Displays the count associated with each word in the wordCount map.
 */

void displayWordCounts(Map<string, int>& wordCounts) {
    for (const string& word : wordCounts) {
        cout << left << setw(15) << word << right << setw(5) << wordCounts[word] << endl;
    }
}

/**
 * Function: extractWords
 * Usage: extractWords(line, words);
 * ---------------------------------
 * Extracts words from the line into the string vector words.
 */

void extractWords(string line, Vector<string>& words) {
    words.clear();
    int start = -1;
    for (int i = 0; i < line.length(); i++) {
        if (isalpha(line[i])) {
            if (start == -1)
                start = i;
        } else {
            if (start >= 0) {
                words.add(line.substr(start, i - start));
                start = -1;
            }
        }
    }
    if (start >= 0)
        words.add(line.substr(start));
}
