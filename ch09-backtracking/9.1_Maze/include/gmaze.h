/*
 * File: gmaze.h
 * -------------
 * This interface exports the Maze class.
 */

#ifndef _gmaze_h
#define _gmaze_h

#include <string>
#include "direction.h"
#include "grid.h"
#include "gwindow.h"
#include "point.h"

/* Defined in Maze.cpp file */
extern Point adjacentPoint(Point start, Direction dir);

/*
 * Function: initGraphics
 * Usage: initGraphics();
 * ------------------------
 * Initializes the Maze package and sets it to use the graphics window
 * provided by default.
 */

void initGraphics();

/*
 * Class: Maze
 * -----------
 * This class represents a two-dimensional maze contained in a rectangular
 * grid of squares.  The maze is read in from a data file in which the
 * characters '+', '-', and '|' represent corners, horizontal walls, and
 * vertical walls, respectively; spaces represent open passageway squares.
 * The starting position is indicated by the character 'S'.  For example,
 * the following data file defines a simple maze:
 *
 *       +-+-+-+-+-+
 *       |     |
 *       + +-+ + +-+
 *       |S  |     |
 *       +-+-+-+-+-+
 */

class Maze {

public:
    /*
     * Constructor: Maze
     * Usage: Maze maze(filename);
     *        Maze maze(filename, gw);
     * -------------------------------
     * Constructs a new maze by reading the specified data file.  If the
     * second argument is supplied, the maze is displayed in the center
     * of the graphics window.
     */

    Maze(std::string filename);
    Maze(std::string filename, GWindow& gw);

    /*
     * Method: getStartPosition
     * Usage: Point start = maze.getStartPosition();
     * ---------------------------------------------
     * Returns a Point indicating the coordinates of the start square.
     */

    Point getStartPosition();

    /*
     * Method: isOutside
     * Usage: if (maze.isOutside(pt)) . . .
     * ------------------------------------
     * Returns true if the specified point is outside the boundary of the maze.
     */

    bool isOutside(Point pt);

    /*
     * Method: wallExists
     * Usage: if (maze.wallExists(pt, dir)) . . .
     * ------------------------------------------
     * Returns true if there is a wall in direction dir from the square at pt.
     */

    bool wallExists(Point pt, Direction dir);

    /*
     * Method: markSquare
     * Usage: maze.markSquare(pt);
     * ---------------------------
     * Marks the specified square in the maze.
     */

    void markSquare(Point pt);

    /*
     * Method: unmarkSquare
     * Usage: maze.unmarkSquare(pt);
     * -----------------------------
     * Unmarks the specified square in the maze.
     */

    void unmarkSquare(Point pt);

    /*
     * Method: isMarked
     * Usage: if (maze.isMarked(pt)) . . .
     * -----------------------------------
     * Returns true if the specified square is marked.
     */

    bool isMarked(Point pt);

    /*
     * Method: showInGraphicsWindow
     * Usage: showInGraphicsWindow();
     *        showInGraphicsWindow(x, y);
     * ----------------------------------
     * Displays the maze in the graphics window, positioned with its origin
     * at the point (x, y), which defaults to center the maze in the window.
     */
    void showInGraphicsWindow();
    void showInGraphicsWindow(double x, double y);

private:
    /* Structure representing a single square */

    struct Square {
        bool marked;
        bool walls[4];
    };

    /* Instance variables */

    Grid<Square> maze;
    Point startSquare;
    double center_x;
    double center_y;
    int rows;
    int cols;

    /* Private functions */

    void readMazeFile(std::string filename);
    void processMazeFile(std::string filename);
    void processDividerLine(std::string line, int y);
    void processPassageLine(std::string line, int y);
    void setHorizontalWall(Point pt);
    void setVerticalWall(Point pt);
    void setStartSquare(Point pt);
    void drawWalls();
    void drawMarks();
    void drawMark(Point pt);
    void eraseMark(Point pt);
};

#endif
