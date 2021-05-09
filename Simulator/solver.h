#ifndef SOLVER_H
#define SOLVER_H

#include "mouse.h"

Action solver(Mouse *mouse);
Action leftWallFollower(Mouse *mouse);
Action floodFill(Mouse *mouse);

//helper functions
void updateWalls(Mouse* mouse);
int leftAccessible(Heading heading, int y_coord, int x_coord);
int rightAccessible(Heading heading, int y_coord, int x_coord);
int frontAccessible(Heading heading, int y_coord, int x_coord);
int getMinValOfNeighbors(Heading heading, int y_coord, int x_coord);
int isInBounds(int x, int y);

struct Coord
{
    int x;
    int y;
};

int debugging();
void enQueue(struct Coord coord);
struct Coord* deQueue();
void display();

void recalculateDistances(Heading heading, int y_coord, int x_coord);
int getFrontAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x);
int getRightAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x);
int getLeftAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x);
int getBackAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x);

int getFrontVal(Heading heading, int y_coord, int x_coord);
int getBackVal(Heading heading, int y_coord, int x_coord);
int getLeftVal(Heading heading, int y_coord, int x_coord);
int getRightVal(Heading heading, int y_coord, int x_coord);

#endif
