/*
 * checkers.h
 *
 * Collective header file for the checkers subsystem:
 * checkersboard.c
 *
 * Contains external interface to the checkers subsystem.
 *
 */

#ifndef CHECKERS_H
#define CHECKERS_H

/* 
 * Checkers boards are represented via a padded array inside the checkers subsystem.
 * checkersboard.c contains code to convert this padded array to a 8x8 array for the core/UI.
 * 
 * The padded array is an int array of length 46, and maps to a checkerboard as follows:
 * 
 *    37  38  39  40
 *  32  33  34  35
 *    28  29  30  31
 *  23  24  25  26
 *    19  20  21  22
 *  14  15  16  17
 *    10  11  12  13
 *  05  06  07  08  
 * 
 * This way, incrementing the array by +5/+4/-4/-5 moves to the space
 * up right/up left/down left/down right or a space that isn't on the board
 * if the move is invalid.
 *
 */

/* common data */


/* checkersboard.c */

int isValidTile(int tile);
int paddedToCoords(int tile, int coords[]);
int coordsToPadded(int tile, int coords[]);


/* checkersmoves.c */



/* checkersgame.c */



#endif

