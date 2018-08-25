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
int paddedToCoords(int tile, int coords[])
{
	if (!isValidTile(tile))
		return 0;

	/* TODO: continue this function */
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
int coordsToPadded(int tile, int coords[])
{
	if (coords[0] % 2 == 0) {
		if (coords[1] % 2 == 0) {
			return -1;
		}
	} else {
		if (coords[1] % 2 != 0) {
			return -1;
		}
	}

	/* TODO: continue this function */
}

