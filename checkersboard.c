/*
 * checkersboard.c
 *
 * Contains board representation code.
 *
 */

#include "checkers.h"

/*
 * Determines if the tile in question is valid, i.e. on the board or not.
 * Requires tile to use the padded array representation (see checkers.h).
 *
 * Returns 0 if false, 1 if true.
 *
 */
int isValidTile(int tile)
{
	if ((tile > 40) || (tile < 5)) {
		return 0;
	}
	switch (tile) {
		case 9:
		case 18:
		case 27:
		case 36:
			return 0;
	}
	return 1;
}

/*
 * Converts a tile from padded array representation (see checkers.h) to
 * an 8x8 representation (in (x,y) format from top left)
 *
 * Inputs:
 * tile: tile to convert, in padded array representation
 * coords: array to store coords in
 *
 * Outputs 0 if tile is invalid, 1 otherwise.
 *
 */
int paddedToCoords(int tile, int coords[2])
{
	if (!isValidTile(tile))
		return 0;

	/* this is ugly but I can't think of a better way... */
	if (tile < 9) {
		coords[1] = 7;
		coords[0] = (tile - 5)*2;
	} else if (tile < 14) {
		coords[1] = 6;
		coords[0] = (tile - 10)*2 + 1;
	} else if (tile < 18) {
		coords[1] = 5;
		coords[0] = (tile - 14)*2;
	} else if (tile < 23) {
		coords[1] = 4;
		coords[0] = (tile - 19)*2 + 1;
	} else if (tile < 27) {
		coords[1] = 3;
		coords[0] = (tile - 23)*2;
	} else if (tile < 32) {
		coords[1] = 2;
		coords[0] = (tile - 28)*2 + 1;
	} else if (tile < 36) {
		coords[1] = 1;
		coords[0] = (tile - 32)*2;
	} else {
		coords[1] = 0;
		coords[0] = (tile - 37)*2 + 1;
	}

	return 1;
}

/*
 * Converts a tile from an 8x8 representation (in (x,y) format from top left) to
 * a padded array representation (see checkers.h).
 *
 * Input:
 * coords: array with coords
 *
 * Outputs the tile in padded array representation,
 * or -1 if coords doesn't describe a valid tile.
 *
 */
int coordsToPadded(int coords[2])
{
	/* test for light squares (assuming pieces are on black squares) */
	if (coords[0] % 2 == 0) {
		if (coords[1] % 2 == 0) {
			return -1;
		}
	} else {
		if (coords[1] % 2 != 0) {
			return -1;
		}
	}
	
	int tile = 0;
	int rows = 8 - coords[1]; /* how many rows are we from the bottom? */

	/* I just reasoned out these formulae using the board diagram in checkers.h */
	if (coords[1] % 2 == 0) {
		tile = rows*4 + rows/2;
		tile += (coords[0]-1)/2 + 1;

	} else {
		tile = rows*4 + (rows-1)/2;
		tile += (coords[0])/2 + 1;
	}

	return tile;
}

