#include <stdlib.h>
#include <stdio.h>
#include "game.h"

void tests() {
	int i;
	Board *board;
	board = malloc(sizeof(Board));
	/* WIN STATES */
	for (i = 0; i < WIN_STATES_COUNT; i++) {
		board->x = WIN_STATES[i];
		display_board(board);
		board->x = 0;
		board->o = WIN_STATES[i];
		display_board(board);
		board->o = 0;
	}

	/* Valid */
	board->x = 0;
	board->o = 84;
	display_board(board);
	for (i = 0; i < AREA; i++) {
		if (valid_move(board, i)) {
			fprintf(stdout, "Move %u is valid\n", i);
		}
	}

	/* Make */
	board->x = 0;
	board->o = 0;
	display_board(board);
	make_move(board, 0);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 1);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 2);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 3);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 4);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 5);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 6);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 7);
	board->turn ^= 1;
	display_board(board);
	make_move(board, 8);
	board->turn ^= 1;
	display_board(board);
	
	free(board);
}

int main() {
	tests();
	return 0;
}
