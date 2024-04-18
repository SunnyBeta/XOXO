CC = cc

CFLAGS   = -ggdb
CFLAGS  += -Wall -Werror -Wextra
CFLAGS  += -pedantic -ansi -std=c89
INCFLAGS = -Iinclude
LDFLAGS  = 

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin

.PHONY: dirs clean

all: dirs ttt

test: dirs src/game.o test.c
	$(CC) src/game.o test.c $(LDFLAGS) $(CFLAGS) $(INCFLAGS) -o $(BIN)/$@
	./$(BIN)/$@
	rm ./$(BIN)/$@

dirs:
	mkdir -p ./bin

ttt: $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $(BIN)/ttt

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(INCFLAGS) -o $@

clean:
	rm -rf $(BIN) $(OBJ)
