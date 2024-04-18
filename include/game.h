#include <stdbool.h>

#define SIZE 3
#define AREA SIZE*SIZE
#define WIN_STATES_COUNT 2*SIZE+2
#define GAMEOVER ((1 << AREA) - 1)

static const int WIN_STATES[] = {7,56,448,73,146,273,292,84};

typedef struct Board {
	unsigned int x;
	unsigned int o;
	unsigned int turn;
	unsigned int history[AREA];
} Board;

Board*       new_board     ();
bool         is_winner     (const int);
bool         valid_move    (Board *, const int);
int          game_over     (Board *);
unsigned int read_move     (Board *);
void         display_board (Board *);
void         make_move     (Board *, const int);
