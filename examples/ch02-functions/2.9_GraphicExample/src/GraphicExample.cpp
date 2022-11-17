/*
 * File: GraphicExample.cpp
 * ---------------------------
 * This program illustrates the use of graphics using the GWindow class.
 */

#include "gwindow.h"

/* Prototypes */

void drawDiamond(GWindow& gw);
void drawRectangleAndOval(GWindow& gw);

/* Main program */

int main() {
    GWindow gw;
    drawDiamond(gw);
    drawRectangleAndOval(gw);
    return 0;
}

/*
 * Function: drawDiamond
 * Usage: drawDiamond(gw);
 * -----------------------
 * Draws a diamond connectiong the midpoints of the window edges.
 */

void drawDiamond(GWindow& gw) {
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.drawLine(0, height / 2, width / 2, 0);
    gw.drawLine(width / 2, 0, width, height / 2);
    gw.drawLine(width, height / 2, width / 2, height);
    gw.drawLine(width / 2, height, 0, height / 2);
}

/*
 * Function: drawRectangleAndOval
 * Usage: drawRectangleAndOval(gw);
 * -----------------------
 * Draws a blue rectangle and a gray oval inscribed in the diamond.
 */

void drawRectangleAndOval(GWindow& gw) {
    double width = gw.getWidth();
    double height = gw.getHeight();
    gw.setColor("BLUE");
    gw.fillRect(width / 4, height / 4, width / 2, height / 2);
    gw.setColor("GRAY");
    gw.fillOval(width / 4, height / 4, width / 2, height / 2);
}
