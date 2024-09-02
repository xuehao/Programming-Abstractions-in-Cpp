/**
 * File: main.cpp
 * --------------
 * Using the Point class
 */

#include <iostream>
#include "console.h"
#include "point_class.h"

using namespace std;

int main() {
    Point pt, origin;
    cout << "pt.x = " << pt.getX() << endl;
    cout << "pt.y = " << pt.getY() << endl;
    cout << "pt = " << pt.toString() << endl;

    if (pt == origin) {
        cout << "The point pt is an origianl point." << endl;
    } else {
        cout << "The point pt is not an origianl point." << endl;
    }

    pt.setX(2);
    pt.setY(3);
    cout << "pt = " << pt << endl;  // overloading <<

    if (pt != origin) {
        cout << "The point pt is not an origianl point." << endl;
    } else {
        cout << "The point pt is an origianl point." << endl;
    }

    return 0;
}
