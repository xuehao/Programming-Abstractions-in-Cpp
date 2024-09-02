/*
 * File: PigLatin.h
 * ----------------
 * Interface for PigLatin
 */

#ifndef PIGLATIN_H
#define PIGLATIN_H
#include <string>

/* Function prototypes */
std::string lineToPigLatin(std::string line);
std::string wordToPigLatin(std::string word);
int findFirstVowel(std::string word);
bool isVowel(char ch);

#endif  // PIGLATIN_H
