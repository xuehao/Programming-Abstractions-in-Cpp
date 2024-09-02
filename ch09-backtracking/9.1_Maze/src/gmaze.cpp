/*
 * File: gmaze.cpp
 * ---------------
 * This file implements the Maze class.
 */

#include "gmaze.h"
#include <fstream>
#include <iostream>
#include <string>
#include "direction.h"
#include "error.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "point.h"
using namespace std;

/* Global pointer to the graphics window */

static GWindow* gwp = nullptr;

void initGraphics() {
    gwp = new GWindow();
}

/* Constants */

static const double SQUARE_SIZE = 30;
static const double MARK_SIZE = 8;
static const double WALL_WIDTH = 2;

/* Public entries */

Maze::Maze(string filename) {
    startSquare = Point(-1, -1);
    readMazeFile(filename);
    processMazeFile(filename);
}

Maze::Maze(string filename, GWindow& gw) {
    if (gwp != nullptr) {
        delete gwp;
    }
    gwp = &gw;
    startSquare = Point(-1, -1);
    readMazeFile(filename);
    processMazeFile(filename);
    center_x = (gw.getWidth() - cols * SQUARE_SIZE) / 2;
    center_y = (gw.getHeight() - rows * SQUARE_SIZE) / 2;
    showInGraphicsWindow(center_x, center_y);
}

Point Maze::getStartPosition() {
    return startSquare;
}

/*
 * Function: isOutside
 * -------------------
 * Returns true if the specified point is outside the boundary of the maze.
 * Axis-y refers to row and axis-x refers to col.
 */

bool Maze::isOutside(Point pt) {
    return !maze.inBounds(pt.getY(), pt.getX());
}

bool Maze::wallExists(Point pt, Direction dir) {
    if (pt.getX() == -1 && dir == EAST) {
        return wallExists(adjacentPoint(pt, EAST), WEST);
    }
    if (pt.getY() == -1 && dir == SOUTH) {
        return wallExists(adjacentPoint(pt, SOUTH), NORTH);
    }
    if (pt.getX() == cols && dir == WEST) {
        return wallExists(adjacentPoint(pt, WEST), EAST);
    }
    if (pt.getY() == rows && dir == NORTH) {
        return wallExists(adjacentPoint(pt, NORTH), SOUTH);
    }
    if (isOutside(pt))
        error("Coordinates are out of range");
    return (maze[pt.getY()][pt.getX()].walls[dir]);
}

void Maze::markSquare(Point pt) {
    if (isOutside(pt))
        error("Coordinates are out of range");
    maze[pt.getY()][pt.getX()].marked = true;
    if (gwp != NULL)
        drawMark(pt);
}

void Maze::unmarkSquare(Point pt) {
    if (isOutside(pt))
        error("Coordinates are out of range");
    maze[pt.getY()][pt.getX()].marked = false;
    if (gwp != NULL)
        eraseMark(pt);
}

bool Maze::isMarked(Point pt) {
    if (isOutside(pt))
        error("Coordinates are out of range");
    return maze[pt.getY()][pt.getX()].marked;
}

/*
 * Method: showInGraphicsWindow
 * Usage: showInGraphicsWindow();
 *        showInGraphicsWindow(x, y);
 * ----------------------------------
 * Displays the maze in the graphics window, positioned with its origin
 * at the point (x, y), which defaults to center the maze in the window.
 */

void Maze::showInGraphicsWindow() {
    center_x = (gwp->getWidth() - cols * SQUARE_SIZE) / 2;
    center_y = (gwp->getHeight() - rows * SQUARE_SIZE) / 2;
    drawWalls();
    drawMarks();
}

void Maze::showInGraphicsWindow(double x, double y) {
    center_x = x;
    center_y = y;
    drawWalls();
    drawMarks();
}

/* Private methods */

/*
 * Method: readMazeFile
 * Usage: readMazeFile(filename);
 * ------------------------------
 * Reads the data file and computes the dimensions of the maze.
 */

void Maze::readMazeFile(std::string filename) {
    ifstream infile;
    if (!openFile(infile, filename))
        error("Cannot open file named " + filename);

    Vector<string> lines;
    readEntireFile(infile, lines);

    rows = (lines.size() - 1) / 2;       // rows is count of lines
    cols = (lines[0].length() - 1) / 2;  // cols is length of line
    maze.resize(rows, cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            for (int i = 0; i < 4; i++) {
                maze[row][col].walls[i] = false;
            }
            maze[row][col].marked = false;
        }
    }
}

/*
 * Method: processMazeFile
 * Usage: processMazeFile(filename);
 * ---------------------------------
 * This method reads the actual maze data from the file.  The
 * methods ComputeMazeSize and InitMazeArray must be called
 * prior to calling ProcessMazeFile.  It is also the caller's
 * responsibility to make sure that infile has been set back
 * to the beginning of the file.
 */

void Maze::processMazeFile(std::string filename) {
    ifstream infile;
    if (!openFile(infile, filename))
        error("Cannot open file named " + filename);

    string line;
    for (int y = 0; y < rows; y++) {
        getline(infile, line);
        processDividerLine(trim(line), y);  // remmove '\r'
        getline(infile, line);
        processPassageLine(trim(line), y);
    }
    getline(infile, line);
    processDividerLine(trim(line), rows);

    if (startSquare.getX() == -1)
        error("Maze contains no start square");
}

/*
 * Method: processDividerLine
 * Usage: processDividerLine(line, y);
 * -----------------------------------
 * This method reads the odd-numbered lines in the data file,
 * which specify the positions of the horizontal walls.  The
 * line have the form
 *
 *     +-+-+-+-+-+-+-+-+
 *
 * where the - symbols may be replaced by spaces to indicate a
 * corridor square.  The y value gives the index of the squares
 * immediately to the north of this line.
 */

void Maze::processDividerLine(string line, int y) {
    int len = line.length();
    if (len != 2 * cols + 1) {
        error("Divider line has incorrect width");
    }
    for (int x = 0; x < cols; x++) {
        if (line[2 * x] != '+')
            error("Missing corner symbol");
        switch (line[2 * x + 1]) {
            case ' ':
                break;
            case '-':
                setHorizontalWall(Point(x, y));
                break;
            default:
                error("Illegal character in maze file");
        }
    }
    if (line[2 * cols] != '+')
        error("Missing corner symbol");
}

/*
 * Method: processPassageLine
 * Usage: processPassageLine(line, y);
 * -----------------------------------
 * This method reads the even-numbered lines in the data file,
 * which specify the passageways and locations of the vertical
 * walls.  These lines have the form
 *
 *     | | | | | | | | |
 *
 * where the | symbols may be replaced by spaces to indicate a
 * corridor square.  One of the open passageway squares in the
 * file may also be marked with an 'S' to indicate the start
 * square.  The y argument gives the index of the squares on
 * this line.
 */

void Maze::processPassageLine(string line, int y) {
    int len = line.length();
    for (int x = 0; x < (len - 1) / 2; x++) {
        if (line[2 * x] == '|') {
            setVerticalWall(Point(x, y));
        }
        switch (line[2 * x + 1]) {
            case ' ':
            case '\0':
                break;
            case 'S':
                setStartSquare(Point(x, y));
                break;
            default:
                error("Illegal character in maze file");
        }
    }
    if (len % 2 == 1 && line[len - 1] == '|') {
        setVerticalWall(Point((len - 1) / 2, y));
    }
}

/*
 * Method: setHorizontalWall
 * Usage: setHorizontalWall(pt);
 * -----------------------------
 * This method sets a horizontal wall to the north of the square
 * at pt.  To maintain consistency in the data structure, it is
 * usually also necessary to create a wall to the south of the
 * square just north of this one.
 */

void Maze::setHorizontalWall(Point pt) {
    if (maze.inBounds(pt.getY(), pt.getX())) {
        maze[pt.getY()][pt.getX()].walls[NORTH] = true;
    }
    if (maze.inBounds(pt.getY() - 1, pt.getX())) {
        maze[pt.getY() - 1][pt.getX()].walls[SOUTH] = true;
    }
}

/*
 * Method: setVerticalWall
 * Usage: setVerticalWall(pt);
 * ---------------------------
 * This method sets a vertical wall to the west of the square
 * at pt.  To maintain consistency in the data structure, it is
 * usually also necessary to create a wall to the east of the
 * square just west of this one.
 */

void Maze::setVerticalWall(Point pt) {
    if (maze.inBounds(pt.getY(), pt.getX())) {
        maze[pt.getY()][pt.getX()].walls[WEST] = true;
    }
    if (maze.inBounds(pt.getY(), pt.getX() - 1)) {
        maze[pt.getY()][pt.getX() - 1].walls[EAST] = true;
    }
}

/*
 * Method: setStartSquare
 * Usage: setStartSquare(pt);
 * --------------------------
 * This method sets the start square to the indicated point and
 * draws a circle on the screen.
 */

void Maze::setStartSquare(Point pt) {
    if (startSquare.getX() != -1) {
        error("Multiple start squares specified");
    }
    startSquare = pt;
}

void Maze::drawWalls() {
    for (int x = 0; x <= cols; x++) {
        double xc = center_x + x * SQUARE_SIZE;
        for (int y = 0; y <= rows; y++) {
            double yc = center_y + y * SQUARE_SIZE;
            Point pt(x, y);
            if (y < rows && wallExists(pt, WEST)) {
                gwp->fillRect(xc, yc, WALL_WIDTH, SQUARE_SIZE + 1);
            }
            if (x < cols && wallExists(pt, NORTH)) {
                gwp->fillRect(xc, yc, SQUARE_SIZE + 1, WALL_WIDTH);
            }
        }
    }
}

void Maze::drawMarks() {
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            Point pt(x, y);
            if (isMarked(pt)) {
                drawMark(pt);
            }
        }
    }
}

void Maze::drawMark(Point pt) {
    double x = center_x + (pt.getX() + 0.5) * SQUARE_SIZE;
    double y = center_y + (pt.getY() + 0.5) * SQUARE_SIZE;
    double delta = MARK_SIZE / 2;
    gwp->setColor("GREEN");
    gwp->drawLine(x - delta, y - delta, x + delta, y + delta);
    gwp->drawLine(x - delta, y + delta, x + delta, y - delta);
    gwp->setColor("BLACK");
    pause(200);
}

void Maze::eraseMark(Point pt) {
    double x = center_x + (pt.getX() + 0.5) * SQUARE_SIZE;
    double y = center_y + (pt.getY() + 0.5) * SQUARE_SIZE;
    double delta = MARK_SIZE / 2;
    gwp->setColor("WHITE");
    gwp->fillRect(x - delta - 1, y - delta - 1, MARK_SIZE + 2, MARK_SIZE + 2);
    gwp->setColor("BLACK");
    pause(200);
}
