/**
 * File: Palindrome.cpp
 * --------------------
 * This program tests for palindromes, which are strings that read the same
 * same backwards and forwards, such as "LEVEL" or "NOON".
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */

bool isPalindrome(string str);

/* Main program */

int main() {
    cout << "This program tests for palindromes." << endl;
    cout << "Enter a blank line to stop." << endl;
    while (true) {
        string word;
        cout << "Enter a word: ";
        getline(cin, word);
        if (word == "")
            break;
        if (isPalindrome(word)) {
            cout << word << " is a palindrome." << endl;
        } else {
            cout << word << " is not a palindrome." << endl;
        }
    }
    return 0;
}

/**
 * Function: isPalindrome
 * Usage: if (isPalindrome(str)) . . .
 * -----------------------------------
 * Returns true if str is a palindrome, which is a string that
 * reads the same backwards and forwards.
 */

bool isPalindrome(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}
