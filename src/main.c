#include <stdio.h>
#include <stdbool.h>
#include "game.h"

int main(int argc, char **argv) {
	unsigned int move;
	int ctr;
	char winner;
	Board *board;

	(void) argc;
	(void) argv;

	move = 10;
	ctr = 0;
	winner = 32;

	board = new_board();
	display_board(board);
	while (!game_over(board) && ctr < AREA) {
		move = read_move(board);
		make_move(board, move);
		board->history[ctr++] = move;
		board->turn ^= 1;
		display_board(board);
		if (is_winner(board->o)) winner = 'O';
		if (is_winner(board->x)) winner = 'X';
		if (winner != 32) {
			fprintf(stdout, "%c is the winner.\n", winner);
			break;
		}
	}
	return 0;
}
