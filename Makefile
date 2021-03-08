CC = gcc
srcfiles = src/main.c src/game.c src/board.c src/gamefunctions.c src/savegame.c
output = cminesweeper

all: $(srcfiles)
	$(CC) -o $(output) -Isrc $(srcfiles) -lncurses -lm
	mkdir -p $(HOME)/.cminesweeper

debug: $(srcfiles)
	$(CC) -o $(output) -Isrc -g -rdynamic -ggdb3 -Wall $(srcfiles) -lncurses -lm
	mkdir -p $(HOME)/.cminesweeper
