/*
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

void testPalindrome(string str);
bool isPalindrome(string str);

/* Main program */

int main() {
   testPalindrome("");
   testPalindrome("x");
   testPalindrome("level");
   testPalindrome("noon");
   testPalindrome("abcdefghgfedcba");
   testPalindrome("0123443210");
   testPalindrome("xyzzy");
   return 0;
}

/*
 * Function: testPalindrome
 * Usage: testPalindrome(str);
 * ---------------------------
 * Tests if the specified string is a palindrome and reports the results.
 */

void testPalindrome(string str) {
   cout << "isPalindrome(\"" << str << "\") -> ";
   cout << (isPalindrome(str) ? "true" : "false" ) << endl;
}

/*
 * Function: isPalindrome
 * Usage: if (isPalindrome(str)) . . .
 * -----------------------------------
 * Returns true if str is a palindrome, which is a string that
 * reads the same backwards and forwards.  This implementation
 * uses the recursive insight that all strings of length 0 or 1
 * are palindromes and that longer strings are palindromes if
 * their first and last characters match and the remaining substring
 * is a palindrome.
 */

bool isPalindrome(string str) {
   int len = str.length();
   if (len <= 1) {
      return true;
   } else {
      return str[0] == str[len - 1] && isPalindrome(str.substr(1, len - 2));
   }
}
