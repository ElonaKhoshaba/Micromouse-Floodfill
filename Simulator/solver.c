#include "solver.h"
#include "mouse.h"

#define TRUE 1;
#define FALSE 0;
int vertArray [16][17] = { 
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
    };
int horizArray [17][16] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
int manhattan [16][16] = {
        {14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14},
        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
        {7,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7},
        {8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8},
        {9,8,7,6,5,4,3,2,2,3,4,5,6,7,8,9},
        {10,9,8,7,6,5,4,3,3,4,5,6,7,8,9,10},
        {11,10,9,8,7,6,5,4,4,5,6,7,8,9,10,11},
        {12,11,10,9,8,7,6,5,5,6,7,8,9,10,11,12},
        {13,12,11,10,9,8,7,6,6,7,8,9,10,11,12,13},
        {14,13,12,11,10,9,8,7,7,8,9,10,11,12,13,14}
    };

//////////////////////////
// Queue Implementation // 
//////////////////////////
#define SIZE 50
struct Coord coordQueue[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull() 
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) 
        return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() 
{
  if (front == -1) 
    return 1;
  return 0;
}

// Adding an element
void enQueue(struct Coord coord) 
{
    if (isFull())
        printf("\n Queue is full!! \n");
    else 
    {
        if (front == -1) 
            front = 0;
        rear = (rear + 1) % SIZE;
        coordQueue[rear] = coord;
        printf("\n Inserted -> (x%d, y%d) \n", coord.x, coord.y);
    }
}

// Removing an element
struct Coord* deQueue() 
{
    struct Coord* coord;
    if (isEmpty()) 
    {
        printf("\n Queue is empty !! \n");
        return -1;
    } 
    else 
    {
        coord = &coordQueue[front];
        if (front == rear) 
        {
            front = -1;
            rear = -1;
        } 
        else  // Q has only one element, so we reset the queue after dequeing it.
            front = (front + 1) % SIZE; 
        printf("\n Deleted element -> (x%d, y%d) \n", coord->x, coord->y);
        return coord;
    }
}

// Display the queue
void display() 
{
    int i;
    if (isEmpty())
        printf(" \n Empty Queue\n");
    else 
    {
        // printf("\n Front -> %d ", front);
        printf("\n coordQueue -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("(x%d, y%d)  ", coordQueue[i].x, coordQueue[i].y);
        }
        printf("(x%d, y%d)  \n", coordQueue[i].x, coordQueue[i].y);
        // printf("\n Rear -> %d \n", rear);
    }
}

int debugging()
{
    // Fails because front = -1
    deQueue();
    struct Coord c1; c1.x = 5; c1.y = 7;
    struct Coord c2; c2.x = 2; c2.y = 4;
    struct Coord c3; c3.x = 1; c3.y = 3;
    struct Coord c4; c4.x = 6; c4.y = 8;
    enQueue(c1);
    enQueue(c2);
    enQueue(c3);
    enQueue(c4);
    struct Coord* coord = deQueue();
    printf("dequeued x: %d \n", coord->x);
    display();
    return 0;
}

//////////////////////
// Driver Functions //
//////////////////////

// This function redirects function calls from mouse.c to the desired maze solving algorithm
Action solver(Mouse *mouse)
{
    // This can be changed to call other maze solving algorithms
    return floodFill(mouse);
    // return debugging();
}

// Simple algorithm; mouse goes straight until encountering a wall, then preferentially turns left
Action obstacleAvoider(Mouse *mouse)
{
    if(getFrontReading(mouse) == 0) return FORWARD;
    else if(getLeftReading(mouse) == 0) return LEFT;
    else if(getRightReading(mouse) == 0) return RIGHT;
    else return LEFT;
}

// Left wall following algorithm
int turnedLeft = 0;
Action leftWallFollower(Mouse *mouse)
{
    if(turnedLeft)
    {
        turnedLeft = 0;
        return FORWARD;
    }
    else if(getLeftReading(mouse) == 0)
    {
        turnedLeft = 1;
        return LEFT;
    }
    else if(getFrontReading(mouse) == 0) return FORWARD;
    else return RIGHT;
}

/////////////////////////
// FloodFill Functions //
/////////////////////////
Action floodFill(Mouse *mouse)
{  
    updateWalls(mouse);
    // for (int i = 0; i < 16; i++)
    // {
    //     for ( int j = 0; j < 17; j++)
    //         printf("%d", vertArray[i][j]);
    //     printf("\n");
    // }
    // printf("END OF VER ARRAY\n");
    // for (int i = 0; i < 17; i++)
    // {
    //     for (int j = 0; j < 16; j++)
    //         printf("%d", horizArray[i][j]);
    //     printf("\n");
    // }
    // printf("END OF HORIZARRAY\n");


    Heading heading = mouse->heading;
    int y_coord = mouse->y;
    int x_coord = mouse->x;

    // Check all three neighboring cells for min value
    int min = getMinValOfNeighbors(heading, y_coord, x_coord);

    int man = manhattan[y_coord][x_coord];
    int front = getFrontVal(heading, y_coord, x_coord);
    int left = getLeftVal(heading, y_coord, x_coord);
    int right = getRightVal(heading, y_coord, x_coord);
    int back = getBackVal(heading, y_coord, x_coord);
    
    if (man == 0)
    {
        return IDLE;
    }
    // printf("Front : %d \n Right : \n Man is :  %d \n Min is : %d \n FrontAccess: %d \n LeftAccess: %d \n RightAccess %d \n\n", front, right, man, min ,  frontAccessible(heading,y_coord,x_coord), leftAccessible(heading,y_coord,x_coord), rightAccessible(heading,y_coord,x_coord));

    if (front != 999 && front < man && frontAccessible(heading, y_coord, x_coord))
    {
        return FORWARD;
    }  
    else if (left != 999 && left < man && leftAccessible(heading, y_coord, x_coord))
    {
        return LEFT;
    }
    else if (right != 999 && right < man && rightAccessible(heading, y_coord, x_coord))
    {
        return RIGHT;
    }
    else if (back != 999 && back < man)
    {
        return RIGHT;
    }
    else
    {
        recalculateDistances(heading, y_coord, x_coord);
        return IDLE;
    }    
}

/////////////////////////////////////
// Recalculate Manhattan Distances //
/////////////////////////////////////

// Called when you hit a wall and there's no accessible min manhattan distance
int count = 0;
void recalculateDistances(Heading heading, int y_coord, int x_coord)
{
    // Add current cell to queue
    struct Coord cur;
    cur.x = x_coord;
    cur.y = y_coord;
    printf("-=-=-=-=-=-=-=-=-=-=-=-ITERATION %d COORD-=-=-=-=-=-=-=-=-=-=-= \n", count);
    count++;
    printf("Heading %d \n", heading);
    enQueue(cur);

    printf("BEGIN MANHATTAN ARRAY\n");
    for (int i = 15; i >= 0; i--)
    {
        for ( int j = 15; j >= 0; j--)
            printf(" %d ", manhattan[i][j]);
        printf("\n");
    }
    Heading getValueHeading;
    // While queue is not empty
    while(!isEmpty())
    {
        getValueHeading = heading;
        // switch (getValueHeading)
        // {
        // case EAST:
        //     getValueHeading = WEST;
        //     break;
        // case WEST:
        //     getValueHeading = EAST;
        //     break;
        // }
        printf(" QUEUE STATUS: ");
        display();
        printf("\n");

        // deQueue cell
        // struct Coord* cell = deQueue();
        // int y = cell->y;
        // int x = cell->x;
        int y  = coordQueue[front].y;
        int x = coordQueue[front].x;
        int min = 777;

        // Get min value of cell's ACCESSIBLE neighbors
        int front = getFrontVal(getValueHeading, y, x);
        int left = getLeftVal(getValueHeading, y, x);
        int right = getRightVal(getValueHeading, y, x);
        int back = getBackVal(getValueHeading, y, x);
        
        if (frontAccessible(heading, y, x) && front != 999 && front < min)
            min = front;
        if (leftAccessible(heading, y, x) && left != 999 && left < min)
            min = left;
        if (rightAccessible(heading, y, x) && right != 999 && right < min)
            min = right;
        if (back != 999 && back < min)
            min = back;

        printf("min is: %d \n", min);
        printf("back: %d \n", back);
        printf("front: %d \n", front);
        printf("left: %d \n", left);
        printf("right: %d \n", right);

        
        // if cell.val <= min
        //  cell.val = min + 1;
        //  and add all accessible neighbors to queue
        // else
        //  continue
        int cellDist = manhattan[y][x];
        printf("cellDist: %d \n", cellDist);
        int newX = 555;
        int newY = 555;
        if (cellDist <= min)
        {
            manhattan[y][x] = min + 1;
            // Add all accessible neighbors to queue
            printf("newX: %d, newY: %d \n", newX, newY);
            if (getFrontAccessibleCoords(heading, y, x, &newY, &newX))
            {
                struct Coord newCoord;
                newCoord.x = newX;
                newCoord.y = newY;
                printf("FRONT newX: %d, newY: %d \n", newX, newY);
                enQueue(newCoord);
            }
            if (getLeftAccessibleCoords(heading, y, x, &newY, &newX))
            {
                struct Coord newCoord;
                newCoord.x = newX;
                newCoord.y = newY;
                printf("LEFT newX: %d, newY: %d \n", newX, newY);
                enQueue(newCoord);
            }
            if (getRightAccessibleCoords(heading, y, x, &newY, &newX))
            {
                struct Coord newCoord;
                newCoord.x = newX;
                newCoord.y = newY;
                printf("RIGHT newX: %d, newY: %d \n", newX, newY);
                enQueue(newCoord);
            }
            if (getBackAccessibleCoords(heading, y, x, &newY, &newX))
            {
                struct Coord newCoord;
                newCoord.x = newX;
                newCoord.y = newY;
                printf("BACK newX: %d, newY: %d \n", newX, newY);
                enQueue(newCoord);
            }
            newX = 888;
            newY = 888;
        }
        deQueue();        
    }
    display();
}


////////////////////////////
// isAccessible Functions //
////////////////////////////
int frontAccessible(Heading heading, int y_coord, int x_coord)
{
    switch(heading)
    {
        case NORTH:
            if (horizArray[y_coord + 1][x_coord] != 1)
                return TRUE;
            break;
        case EAST:
            if (vertArray[y_coord][x_coord + 1] != 1)
                return TRUE;
            break;
        case WEST:
            if (vertArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
        case SOUTH:
            if (horizArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
    }
    return FALSE;
}

int leftAccessible(Heading heading, int y_coord, int x_coord)
{
    switch(heading)
    {
        case NORTH:
            if (vertArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
        case EAST:
            if (horizArray[y_coord + 1][x_coord] != 1)
                return TRUE;
            break;
        case WEST:
            if (horizArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
        case SOUTH:
            if (vertArray[y_coord][x_coord + 1] != 1)
                return TRUE;
            break;
    }
    return FALSE;
}

int rightAccessible(Heading heading, int y_coord, int x_coord)
{
    switch(heading)
    {
        case NORTH:
            if (vertArray[y_coord][x_coord + 1] != 1)
                return TRUE;
            break;
        case EAST:
            if (horizArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
        case WEST:
            if (horizArray[y_coord + 1][x_coord] != 1)
                return TRUE;
            break;
        case SOUTH:
            if (vertArray[y_coord][x_coord] != 1)
                return TRUE;
            break;
    }
    return FALSE;
}

////////////////////////
// getValue Functions // 
////////////////////////
int getFrontVal(Heading heading, int y_coord, int x_coord)
{
    switch (heading)
    {
        case NORTH: 
            if (isInBounds (y_coord + 1, x_coord))
                return manhattan[y_coord + 1][x_coord];
            break;
        case WEST:
            if (isInBounds (y_coord, x_coord - 1))
                return manhattan[y_coord][x_coord - 1];
            break;
        case EAST:  
            if (isInBounds (y_coord, x_coord + 1))
                return manhattan[y_coord][x_coord + 1];
            break; 
        case SOUTH:  
            if (isInBounds (y_coord - 1, x_coord))
                return manhattan[y_coord - 1][x_coord];
            break; 
    }
    return 999;
}

int getLeftVal(Heading heading,  int y_coord, int x_coord)
{
    switch (heading)
    {
        case NORTH:
            if (isInBounds(y_coord,x_coord - 1))
                return manhattan[y_coord][x_coord - 1];
            break;
        case EAST:
            if (isInBounds(y_coord + 1, x_coord))
                return manhattan[y_coord + 1][x_coord];
            break;
        case WEST:  
            if (isInBounds(y_coord - 1, x_coord))
                return manhattan[y_coord - 1][x_coord];
            break;
        case SOUTH:  
            // printf("leftx_coord: %d \n left y_coord-1: %d \n", y_coord, x_coord-1);
            if (isInBounds(y_coord, x_coord + 1))
                return manhattan[y_coord][x_coord + 1];
            break;
    }
    return 999;
}

int getRightVal(Heading heading, int y_coord, int x_coord)
{
    switch (heading)
    {
        case NORTH:  
            if (isInBounds(y_coord, x_coord + 1))
                return manhattan[y_coord][x_coord + 1];
            break;
        case EAST:
            if (isInBounds(y_coord - 1, x_coord))
                return manhattan[y_coord-1][x_coord];
            break;
        case WEST:
            if (isInBounds(y_coord + 1, x_coord))
                return manhattan[y_coord + 1][x_coord];
            break;
        case SOUTH: 
            if (isInBounds(y_coord, x_coord - 1))
                return manhattan[y_coord][x_coord - 1];
            break;  
    }
    return 999;
}

int getBackVal(Heading heading, int y_coord, int x_coord)
{
    switch (heading)
    {
        case NORTH: 
            if (isInBounds (y_coord - 1, x_coord))
                return manhattan[y_coord - 1][x_coord];
            break;
        case WEST:
            if (isInBounds (y_coord, x_coord + 1))
                return manhattan[y_coord][x_coord + 1];
            break;
        case EAST:  
            if (isInBounds (y_coord, x_coord - 1))
                return manhattan[y_coord][x_coord - 1];
            break; 
        case SOUTH:  
            if (isInBounds (y_coord + 1, x_coord))
                return manhattan[y_coord + 1][x_coord];
            break; 
    }
    return 999;
}

/////////////
// Helpers //
/////////////
int getMinValOfNeighbors(Heading heading, int y_coord, int x_coord)
{
    int min = 1000;
    int front = getFrontVal(heading, y_coord, x_coord);
    int left = getLeftVal(heading, y_coord, x_coord);
    int right = getRightVal(heading, y_coord, x_coord);
    // printf ("front: %d \n left: %d \n right: %d \n", front, left, right);

    if (front != 999 && front < min)
        min = front;
    if (left != 999 && left < min)
        min = left;
    if (right != 999 && right < min)
        min = right;
    return min;
}

int isInBounds(int x, int y)
{
    if(x < 0 || y < 0 || y > 15 || x > 15)
        return FALSE;
    return TRUE;
}

void updateWalls(Mouse* mouse)
{
    int y_coord = mouse->y;
    int x_coord = mouse->x;
    // printf("Y coord is %d\n", y_coord);
    // printf("X coord is %d\n", x_coord);
    
    if (getFrontReading(mouse) == 1)
    {
        if (mouse->heading == NORTH)
            horizArray[y_coord + 1][x_coord] = 1;
        else if (mouse->heading == EAST)
            vertArray[y_coord][x_coord + 1] = 1;
        else if (mouse->heading == WEST)
            vertArray[y_coord][x_coord] = 1;
        else if (mouse->heading ==SOUTH)
            horizArray[y_coord][x_coord] = 1;
    }
    if (getLeftReading(mouse) == 1)
    {
        if (mouse->heading == NORTH)
            vertArray[y_coord][x_coord] = 1;
        else if (mouse->heading == EAST)
            horizArray[y_coord + 1][x_coord] = 1;
        else if (mouse->heading == WEST)
            horizArray[y_coord][x_coord] = 1;
        else if (mouse->heading == SOUTH)
            vertArray[y_coord][x_coord + 1] = 1;
    }
    if (getRightReading(mouse) == 1)
    {
        if (mouse->heading == NORTH)
            vertArray[y_coord][x_coord + 1] = 1;
        else if (mouse->heading == EAST)
            horizArray[y_coord][x_coord] = 1;
        else if (mouse->heading == WEST)
            horizArray[y_coord + 1][x_coord] = 1;
        else if (mouse->heading == SOUTH)
            vertArray[y_coord][x_coord] = 1;
    }
}

//////////////////////////////
// Get Accessible Functions //
//////////////////////////////
int getFrontAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x)
{
    switch(heading)
    {
        case NORTH:
            if (horizArray[y_coord + 1][x_coord] != 1)
            {
                *new_y = y_coord + 1;
                *new_x = x_coord;
                return TRUE;    
            }  
            break;
        case EAST:
            if (vertArray[y_coord][x_coord + 1] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord + 1;
                return TRUE;    
            } 
            break;
        case WEST:
            if (vertArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord - 1;
                return TRUE;    
            } 
            break;
        case SOUTH:
            if (horizArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord - 1;
                *new_x = x_coord;
                return TRUE;    
            } 
            break;
    }
    return FALSE;
}

int getLeftAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x)
{
    switch(heading)
    {
        case NORTH:
            if (vertArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord - 1;
                return TRUE;    
            } 
            break;
        case EAST:
            if (horizArray[y_coord + 1][x_coord] != 1)
            {
                *new_y = y_coord  + 1;
                *new_x = x_coord;
                return TRUE;    
            } 
            break;
        case WEST:
            if (horizArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord - 1;
                *new_x = x_coord;
                return TRUE;    
            } 
            break;
        case SOUTH:
            if (vertArray[y_coord][x_coord + 1] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord + 1;
                return TRUE;    
            } 
            break;
    }
    return FALSE;
}

int getRightAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x)
{
    switch(heading)
    {
        case NORTH:
            if (vertArray[y_coord][x_coord + 1] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord + 1;
                return TRUE;    
            } 
            break;
        case EAST:
            if (horizArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord - 1;
                *new_x = x_coord;
                return TRUE;    
            } 
            break;
        case WEST:
            if (horizArray[y_coord + 1][x_coord] != 1)
            {
                *new_y = y_coord + 1;
                *new_x = x_coord;
                return TRUE;    
            } 
            break;
        case SOUTH:
            if (vertArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord - 1;
                printf("In getRightAccessibleCoord SOUTH \n");
                return TRUE;    
            } 
            break;
    }
    return FALSE;
}

int getBackAccessibleCoords(Heading heading, int y_coord, int x_coord, int* new_y, int* new_x)
{
    printf("In getBackAccessibleCoords above switch statement \n");
    switch(heading)
    {
        case NORTH:
            if (horizArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord - 1;
                *new_x = x_coord;
                printf("In getBackAccessibleCoord NORTH \n");
                return TRUE;    
            }  
            break;
        case EAST:
            if (vertArray[y_coord][x_coord] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord - 1;
                printf("In getBackAccessibleCoord EAST \n");
                return TRUE;    
            } 
            break;
        case WEST:
            if (vertArray[y_coord][x_coord + 1] != 1)
            {
                *new_y = y_coord;
                *new_x = x_coord + 1;
                printf("In getBackAccessibleCoord WEST \n");
                return TRUE;    
            } 
            break;
        case SOUTH:
            if (horizArray[y_coord + 1][x_coord] != 1)
            {
                *new_y = y_coord + 1;
                *new_x = x_coord;
                printf("In getBackAccessibleCoord SOUTH \n");
                return TRUE;    
            } 
            break;
    }
    return FALSE;
}

