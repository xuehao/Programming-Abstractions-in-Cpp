/*
 * File: Anagrams.cpp
 * ------------------
 * This file generates all legal anagrams of a sequence of letters.
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
#include "set.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

Set<string> generatePermutations(string str);

/* Main program */

int main() {
   Lexicon english("EnglishWords.dat");
   string letters = getLine("Enter the letters: ");
   cout << "The anagrams of " << letters << " are:" << endl;
   for (string word: generatePermutations(letters)) {
      if (english.contains(word)) {
         cout << "  " << word << endl;
      }
   }
   return 0;
}

/*
 * Function: generatePermutations
 * Usage: Set<string> permutations = generatePermutations(str);
 * ------------------------------------------------------------
 * Returns a set consisting of all permutations of the specified string.
 * This implementation uses the recursive insight that you can generate
 * all permutations of a string by selecting each character in turn,
 * generating all permutations of the string without that character,
 * and then concatenating the selected character on the front of each
 * string generated.
 */

Set<string> generatePermutations(string str) {
   Set<string> result;
   if (str == "") {
      result += "";
   } else {
      for (int i = 0; i < str.length(); i++) {
         char ch = str[i];
         string rest = str.substr(0, i) + str.substr(i + 1);
         for (string s: generatePermutations(rest)) {
            result += ch + s;
         }
      }
   }
   return result;
}
