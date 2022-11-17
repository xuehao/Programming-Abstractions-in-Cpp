/**
 * File: PigEnglish.cpp
 * --------------------
 * This program finds all English words that remain words when
 * you convert them to Pig Latin, such as "trash" (which becomes
 * "ashtray") and "entry" (which becomes "entryway"). The code
 * ignores words containing no vowels (mostly Welsh-derived
 * words like "cwm"), which don't change form under the Pig Latin
 * rules introduced in Chapter 3.
 */

#include <cctype>
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
using namespace std;

/* Function prototypes */

string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

/* Main program */

int main() {
    cout << "This program finds words that remain words"
         << " when translated to Pig Latin." << endl;
    Lexicon english("EnglishWords.dat");
    for (const string& word : english) {
        string pig = wordToPigLatin(word);
        if (pig != word && english.contains(pig)) {
            cout << word << " -> " << pig << endl;
        }
    }
    return 0;
}

/**
 * Function: wordToPigLatin
 * Usage: string translation = wordToPigLatin(word);
 * -------------------------------------------------
 * This function translates a word from English to Pig Latin using
 * the rules specified in the text. The translated word is
 * returned as the value of the function.
 */

std::string wordToPigLatin(std::string word) {
    int vp = findFirstVowel(word);
    if (vp == -1) {
        return word;
    } else if (vp == 0) {
        return word + "way";
    } else {
        std::string head = word.substr(0, vp);
        std::string tail = word.substr(vp);
        return tail + head + "ay";
    }
}

/**
 * Function: findFirstVowel
 * Usage: int k = findFirstVowel(word);
 * ------------------------------------
 * Returns the index position of the first vowel in word. If
 * word does not contain a vowel, findFirstVowel returns -1.
 */

int findFirstVowel(std::string word) {
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i]))
            return i;
    }
    return -1;
}

/**
 * Function: isVowel
 * Usage: if (isVowel(ch)) . . .
 * -----------------------------
 * Returns true if the character ch is a vowel.
 */

bool isVowel(char ch) {
    switch (ch) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}
