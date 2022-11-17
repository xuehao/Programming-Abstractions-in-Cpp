/**
 * File: point_class.cpp
 * ---------------------
 * This file implements the point.h interface.
 */

#include "point_class.h"
#include <string>
#include "strlib.h"
using namespace std;

/**
 * Implementation notes: Constructors
 * ----------------------------------
 * The constructors initialize the instance variables x and y. In the
 * second form of the constructor, the parameter names are xc and yc
 * to avoid the problem of shadowing the instance variables.
 */

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xc, int yc) {
    x = xc;
    y = yc;
}

/**
 * Implementation notes: Getters
 * -----------------------------
 * The getters return the value of the corresponding instance variable.
 */

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

/**
 * Implementation notes: Setters
 * -----------------------------
 * The setters set the value of the corresponding instance variable.
 */

void Point::setX(int value) {
    x = value;
}

void Point::setY(int value) {
    y = value;
}

/**
 * Implementation notes: ==
 * -----------------------------
 * The operator == supports testing the equality of two points.
 */

bool Point::operator==(Point p2) {
    return x == p2.x && y == p2.y;
}

/**
 * Implementation notes: toString
 * ------------------------------
 * The implementation of toString uses the integerToString function
 * from the strlib.h interface.
 */

string Point::toString() {
    return "(" + integerToString(x) + "," + integerToString(y) + ")";
}

/**
 * Implementation notes: operator<<
 * ----------------------------------------
 * The insertion operator supports displaying point objects as strings.
 */

ostream& operator<<(ostream& os, Point pt) {
    return os << pt.toString();
}

/**
 * Implementation notes: !=
 * -----------------------------
 * The operator != supports testing the equality of two points.
 */

bool operator!=(Point p1, Point p2) {
    return !(p1 == p2);
}
