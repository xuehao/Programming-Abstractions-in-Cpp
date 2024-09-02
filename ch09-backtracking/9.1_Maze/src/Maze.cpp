/**
 * File: Maze.cpp
 * ---------------
 * This program solves the Maze puzzle.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "direction.h"
#include "gmaze.h"
#include "point.h"
using namespace std;

// Function prototypes

bool solveMaze(Maze& maze, Point start);
Point adjacentPoint(Point start, Direction dir);

// Main program

int main() {
    initGraphics();
    Maze maze("6x6.maze");
    maze.showInGraphicsWindow();
    if (solveMaze(maze, maze.getStartPosition())) {
        cout << "The marked path is a solution." << endl;
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}

/*
 * Function: solveMaze
 * Usage: solveMaze(maze, start);
 * ------------------------------
 * Attempts to generate a solution to the current maze from the specified
 * start point. The solveMaze function returns true if the maze has a
 * solution and false otherwise. The implementation uses recursion
 * to solve the submazes that result from marking the current square
 * and moving one step along each open passage.
 */

bool solveMaze(Maze& maze, Point start) {
    if (maze.isOutside(start))
        return true;
    if (maze.isMarked(start))
        return false;
    maze.markSquare(start);
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!maze.wallExists(start, dir)) {
            if (solveMaze(maze, adjacentPoint(start, dir))) {
                return true;
            }
        }
    }
    maze.unmarkSquare(start);
    return false;
}

/*
 * Function: adjacentPoint
 * Usage: Point finish = adjacentPoint(start, dir);
 * ------------------------------------------------
 * Returns the Point that results from moving one square from start
 * in the direction specified by dir.  For example, if pt is the
 * point (1, 1), calling adjacentPoint(pt, EAST) returns the
 * point (2, 1).  To maintain consistency with the graphics package,
 * the y coordinates increase as you move downward on the screen.  Thus,
 * moving NORTH decreases the y component, and moving SOUTH increases it.
 */

Point adjacentPoint(Point start, Direction dir) {
    switch (dir) {
        case NORTH:
            return Point(start.getX(), start.getY() - 1);
        case EAST:
            return Point(start.getX() + 1, start.getY());
        case SOUTH:
            return Point(start.getX(), start.getY() + 1);
        case WEST:
            return Point(start.getX() - 1, start.getY());
    }
    return start;
}
