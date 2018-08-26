/*
 * main.c
 *
 */

#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include "checkers.h"

/* 
 * Draw the outline of the board.
 * The board is 33 across and 25 down.
 *
 * Returns 1.
 */
int draw_board_outline()
{
	move(1,0);
	for (int i=0; i<8; i++) {
	printw(" +---+---+---+---+---+---+---+---+\n");
	printw(" |   |   |   |   |   |   |   |   |\n");
	printw(" |   |   |   |   |   |   |   |   |\n");
	}
	printw(" +---+---+---+---+---+---+---+---+\n");
	return 1;
}

/* 
 * Draws the given checkers board.
 *
 * Inputs:
 * board[45] - the board in padded array representation.
 *
 * Returns 1.
 *
 */
int draw_board(int board[46])
{
	move(26,1);
	for (int i=0; i < 46; i++) {
		printw("%d ", board[i]);
	}
	for (int i=0; i < 46; i++) {
		if ((board[i] != INVALID) && (board[i] != EMPTY)) {
			int coords[2];
			paddedToCoords(i, coords);
			move((coords[1]+1)*3,(coords[0]+1)*4-1-1);
			printw("%d", coords[0]);
			switch (board[i]) {
				case WHITE:
					printw("w");
					break;
				case BLACK:
					printw("b");
					break;
				case WHITEKING:
					printw("W");
					break;
				case BLACKKING:
					printw("B");
					break;
			}
			printw("%d", coords[1]);
		}
	}
	return 1;
}


int main(int argc, char *argv[])
{
	initscr();
	keypad(stdscr, TRUE); 
	noecho();
	curs_set(FALSE);

	int pos[2] = {0,0}; /* (x,y) */
	int theboard[46];
	boardCopy(startingboard,theboard);

	bool exit = false;
	while (!exit) {
		clear();

		draw_board_outline();
		draw_board(theboard);

		move((pos[1]+1)*3-1,(pos[0]+1)*4-1);
		printw("*");

		move(27,1);
		printw("pos: %d, %d; tile: %d; type: %d", pos[0], pos[1], coordsToPadded(pos), theboard[coordsToPadded(pos)]);

		refresh();

		char ch = getch();
		switch (ch) {
			/* quit */
			case 'q':
				exit=true;
				break;

			/* movement commands */
			case 'w':
				if (pos[1] > 0)
					pos[1]--;
				break;
			case 's': 
				if (pos[1] < 7)
					pos[1]++;
				break;
			case 'a':
				if (pos[0] > 0)
					pos[0]--;
				break;
			case 'd': 
				if (pos[0] < 7)
					pos[0]++;
				break;
		}
	}

	endwin();

	/* test code
	int coords[2] = {0,1};	printf("%d\n", coordsToPadded(coords));
	int qcoords[2] = {5,5};	printf("%d\n", coordsToPadded(qcoords));
	int wcoords[2] = {4,3};	printf("%d\n", coordsToPadded(wcoords));
	int ecoords[2] = {5,0};	printf("%d\n", coordsToPadded(ecoords));
	int rcoords[2] = {7,5};	printf("%d\n", coordsToPadded(rcoords));
	int tcoords[2] = {4,5};	printf("%d\n", coordsToPadded(tcoords));
	int ycoords[2] = {2,3};	printf("%d\n", coordsToPadded(ycoords));
	int ucoords[2] = {4,6};	printf("%d\n", coordsToPadded(ucoords));

	int coords[2];
	paddedToCoords(37, coords); printf("%d, %d\n", coords[0], coords[1]);
	paddedToCoords(29, coords); printf("%d, %d\n", coords[0], coords[1]);
	paddedToCoords(18, coords); printf("%d, %d\n", coords[0], coords[1]);
	paddedToCoords(15, coords); printf("%d, %d\n", coords[0], coords[1]);
	paddedToCoords(8, coords); printf("%d, %d\n", coords[0], coords[1]);
	*/

	/* test code
	int startboard[45];
	boardCopy(startingboard, startboard);
	printf("%d\n", countPieces(startboard, WHITE));
	printf("%d\n", countPieces(startboard, EMPTY));
	printf("%d\n", countPieces(startboard, BLACK));
	for (int i=0; i < 46; i++) {
		printf("%d\n", startboard[i]);
	}
	*/

	return 0;
}

