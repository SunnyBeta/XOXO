#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

Board *new_board() {
	int i;
	Board *board;

	board = malloc(sizeof(Board));
	if (board == NULL) fprintf(stderr, "Out of Mmeory!");
	board->turn = 1;
	board->x = 0;
	board->o = 0;
	for (i = 0; i < AREA; i++) board->history[i] = 0;
	return board;
}

bool valid_move(Board *board, const int move) {
	if ((move > AREA-1) || (move < 0))       return false;
	if ((board->x | board->o) & (1 << move)) return false;
	return true;
}

unsigned int read_move(Board *board) {
	unsigned int move;
	do { 
		printf("Enter Move (1-%d): ", AREA);
		scanf("%u", &move);
		--move;
	} while(!valid_move(board, move));
	return move;
}


void make_move(Board *board, const int move) {
	unsigned int *player = board->turn?&board->x:&board->o;
	*player = *player | (1 << move);
}

int game_over(Board *board) {
	return (is_winner(board->x) || is_winner(board->o) || ((board->x | board->o) == GAMEOVER));
}

void display_board(Board *board) {
	int cell;
	putchar('\n');
	for (cell = 0; cell < AREA; cell++) {
		if      ((board->x >> cell) & 1) putchar('X');
		else if ((board->o >> cell) & 1) putchar('O');
		else                             putchar('-');
		if (cell % SIZE == SIZE-1) putchar('\n');
	}
	putchar('\n');
	printf("TURN: %c\n\n", board->turn?'X':'O');
}

bool is_winner(const int board) {
	int i;
	for (i = 0; i < WIN_STATES_COUNT; i++)
		if ((WIN_STATES[i] & board) == WIN_STATES[i])
			return true;
	return false;
}
