/**
 * File: tokenscanner.h
 * --------------------
 * This file exports a simple TokenScanner class that divides a string
 * into individual logical units called tokens. In this version
 * of the package, tokens come in two forms:
 *
 * 1. Strings of consecutive letters and digits representing words
 * 2. One-character strings representing punctuation or separators
 *
 * The use of the TokenScanner class is illustrated by the following code
 * pattern, which reads the tokens in the string variable input:
 *
 * TokenScanner scanner;
 * scanner.setInput(input);
 * while (scanner.hasMoreTokens()) {
 * string token = scanner.nextToken();
 * . . . process the token . . .
 * }
 *
 * This version of the TokenScanner class includes the ignoreWhitespace
 * method. The other options available in the library version of the
 * class are included as exercises in the text.
 */
#ifndef _mytokenscanner_h
#define _mytokenscanner_h

#include <string>

/**
 * Class: TokenScanner
 * -------------------
 * This class is used to represent a single instance of a scanner.
 */

class MyTokenScanner {
public:
    /**
     * Constructor: TokenScanner
     * Usage: TokenScanner scanner;
     * TokenScanner scanner(str);
     * ---------------------------------
     * Initializes a scanner object. The initial token stream comes from
     * the string str, if it is specified. The default constructor creates
     * a scanner with an empty token stream.
     */

    MyTokenScanner();
    MyTokenScanner(std::string str);

    /**
     * Method: setInput
     * Usage: scanner.setInput(str);
     * -----------------------------
     * Sets the input for this scanner to the specified string. Any
     * previous input string is discarded.
     */

    void setInput(std::string str);

    /**
     * Method: hasMoreTokens
     * Usage: if (scanner.hasMoreTokens()) . . .
     * -----------------------------------------
     * Returns true if there are additional tokens for this scanner to read.
     */

    bool hasMoreTokens();

    /**
     * Method: nextToken
     * Usage: token = scanner.nextToken();
     * -----------------------------------
     * Returns the next token from this scanner. If called when no tokens
     * are available, nextToken returns the empty string.
     */

    std::string nextToken();

    /**
     * Method: ignoreWhitespace()
     * Usage: scanner.ignoreWhitespace();
     * ----------------------------------
     * Tells the scanner to ignore whitespace characters. By default, the
     * nextToken method treats whitespace characters (typically spaces and
     * tabs) just like any other punctuation mark and returns them as
     * single-character tokens. Calling
     *
     * scanner.ignoreWhitespace();
     *
     * changes this behavior so that the scanner ignore whitespace characters.
     */

    void ignoreWhitespace();

private:
    /* Instance variables */
    std::string buffer;        /* The input string containing the tokens */
    int cp;                    /* The current position in the buffer */
    bool ignoreWhitespaceFlag; /* Flag set by a call to ignoreWhitespace */
    void skipWhitespace();     /* Private methods */
};
#endif
