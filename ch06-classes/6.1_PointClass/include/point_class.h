/**
 * File: point_class.h
 * -------------------
 * This interface exports the Point class, which represents a point on
 * a two-dimensional integer grid.
 */

#ifndef _point_class_h
#define _point_class_h

#include <string>

class Point {
public:
    /**
     * Constructor: Point
     * Usage: Point origin;
     * Point pt(xc, yc);
     * ------------------------
     * Creates a Point object. The default constructor sets the coordinates
     * to 0; the second form sets the coordinates to xc and yc.
     */

    Point();
    Point(int xc, int yc);

    /**
     * Methods: getX, getY
     * Usage: int x = pt.getX();
     * int y = pt.getY();
     * -------------------------
     * These methods returns the x and y coordinates of the point.
     */

    int getX();
    int getY();

    /**
     * Methods: setX, setY
     * Usage: pt.setX(2);
     *        pt.setY(3);
     * -------------------------
     * These methods set the x and y coordinates of the point.
     */

    void setX(int value);
    void setY(int value);

    /**
     * Operator: ==
     * Usage: p1 == p2
     * ---------------
     * This operator supports equality testing for points.
     */

    bool operator==(Point p2);

    /**
     * Method: toString
     * Usage: string str = pt.toString();
     * ----------------------------------
     * Returns a string representation of the Point in the form "(x,y)".
     */

    std::string toString();

private:
    int x; /* The x-coordinate */
    int y; /* The y-coordinate */
};

/**
 * Operator: <<
 * Usage: cout << pt;
 * ------------------
 * Overloads the << operator so that it is able to display Point values.
 */

std::ostream& operator<<(std::ostream& os, Point pt);

/**
 * Operator: !=
 * Usage: p1 != p2
 * ---------------
 * This operator implements the != operator for points. It is good
 * practice to overload this operator whenever you overload == to
 * ensure that clients can perform either test.
 */

bool operator!=(Point p1, Point p2);

#endif
