/*
 * File: ShowFileContents.cpp
 * --------------------------
 * This program displays the contents of a file chosen by the user.
 */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* Function prototypes */
string promptUserForFile(ifstream& infile, string prompt = "");

/* Main program */
int main() {
    ifstream infile;
    promptUserForFile(infile, "Input file(e.g. Jabberwocky.txt): ");
    while (true) {
        // int ch = infile.get();
        // if (ch == EOF)
        //     break;
        // cout.put(ch);
        string line;
        getline(infile, line);
        if (infile.fail())
            break;
        cout << line << endl;
    }
    infile.close();
    return 0;
}

/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(infile, prompt);
 * -----------------------------------------------------------
 * Asks the user for the name of an input file and opens the reference
 * parameter infile using that name, which is returned as the result of
 * the function. If the requested file does not exist, the user is
 * given additional chances to enter a valid file name. The optional
 * prompt argument is used to give the user more information about the
 * desired input file.
 */
string promptUserForFile(ifstream& infile, string prompt) {
    while (true) {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail())
            return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if (prompt == "")
            prompt = "Input file: ";
    }
}
