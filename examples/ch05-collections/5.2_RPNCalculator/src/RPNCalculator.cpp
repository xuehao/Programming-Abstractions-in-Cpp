/**
 * File: RPNCalculator.cpp
 * -----------------------
 * This program simulates an electronic calculator that uses
 * reverse Polish notation, in which the operators come after
 * the operands to which they apply. Information for users
 * of this application appears in the helpCommand function.
 */

#include <cctype>
#include <iostream>
#include <string>
#include "console.h"
#include "error.h"
#include "simpio.h"
#include "stack.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void applyOperator(char op, Stack<double>& operandStack);
void helpCommand();

/* Main program */

int main() {
    cout << "RPN Calculator Simulation (type H for help)" << endl;
    Stack<double> operandStack;
    while (true) {
        string line = getLine("> ");
        if (line.length() == 0)
            line = "Q";
        char ch = toupper(line[0]);
        if (ch == 'Q') {
            break;
        } else if (ch == 'C') {
            operandStack.clear();
        } else if (ch == 'H') {
            helpCommand();
        } else if (isdigit(ch)) {
            operandStack.push(stringToReal(line));
        } else {
            applyOperator(ch, operandStack);
        }
    }
    return 0;
}

/**
 * Function: applyOperator
 * Usage: applyOperator(op, operandStack);
 * ---------------------------------------
 * This function applies the operator to the top two elements on
 * the operand stack. Because the elements on the stack are
 * popped in reverse order, the right operand is popped before
 * the left operand.
 */

void applyOperator(char op, Stack<double>& operandStack) {
    double result;
    double rhs = operandStack.pop();
    double lhs = operandStack.pop();
    switch (op) {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
        default:
            error("Illegal operator");
    }
    cout << result << endl;
    operandStack.push(result);
}

/**
 * Function: helpCommand
 * Usage: helpCommand();
 * ---------------------
 * This function generates a help message for the user.
 */

void helpCommand() {
    cout << "Enter expressions in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which" << endl;
    cout << "they apply. Each line consists of a number, an" << endl;
    cout << "operator, or one of the following commands:" << endl;
    cout << " Q -- Quit the program" << endl;
    cout << " H -- Display this help message" << endl;
    cout << " C -- Clear the calculator stack" << endl;
}
