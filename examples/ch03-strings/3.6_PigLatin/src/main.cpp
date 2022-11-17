/*
 * File: main.cpp
 * ------------------
 * This program converts lines from English to Pig Latin.
 * This dialect of Pig Latin applies the following rules:
 *
 * 1. If the word contains no vowels, return the original
 * word unchanged.
 *
 * 2. If the word begins with a consonant, extract the set
 * of consonants up to the first vowel, move that set
 * of consonants to the end of the word, and add "ay".
 *
 * 3. If the word begins with a vowel, add "way" to the
 * end of the word.
 */

#include <iostream>
#include "PigLatin.h"
#include "console.h"

using std::cin;
using std::cout;
using std::endl;

/* Main program */
int main() {
    cout << "This program translates English to Pig Latin." << endl;
    std::string line;
    cout << "Enter English text: ";
    getline(cin, line);
    std::string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
    return 0;
}
