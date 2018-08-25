/*
 * main.c
 *
 */

#include <stdio.h>
#include <ncurses.h>
#include "checkers.h"

/* 
 * Draw the outline of the board.
 * The board is 33 across and 25 down.
 */
bool draw_board_outline()
{
	move(1,0);
	for (int i=0; i<8; i++) {
	printw(" +---+---+---+---+---+---+---+---+\n");
	printw(" |   |   |   |   |   |   |   |   |\n");
	printw(" |   |   |   |   |   |   |   |   |\n");
	}
	printw(" +---+---+---+---+---+---+---+---+\n");
	return true;
}

int main(int argc, char *argv[])
{
	initscr();
	keypad(stdscr, TRUE); 
	noecho();
	curs_set(FALSE);

	int pos[2] = {0,0}; /* (x,y) */

	bool exit = false;
	while (!exit) {
		clear();
		draw_board_outline();
		move((pos[1]+1)*3-1,(pos[0]+1)*4-1);
		printw("*");
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

	return 0;
}

