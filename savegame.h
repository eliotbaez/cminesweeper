/* savegame.h */

#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <stdlib.h>
#include <stdint.h>
#include <time.h>	/* clock_t */
#include "board.h"

#define MASK_FLAG_MODE		0x01
#define MASK_FIRST_CLICK	0x02

/* struct storing the state of the game */
typedef struct {
	int64_t size;			/* the size of the board data */
	int32_t width, height;	/* dimensions of game board */
	int32_t qtyMines;		/* number of mines in the game */
	int32_t flagsPlaced;	/* flags placed by user */
	uint32_t gameBools;		/* integer storing the state of in-game bools */
	int32_t cy, cx;			/* cursor coordinates */
	clock_t timeOffset;		/* game duration in seconds */
	uint8_t * gameData;		/* string of bytes storing board and mine data */
} Savegame;

/* utility function declarations */

/* decodes game data from the savegame into the mine and board structs */
int getGameData (Board * mines, Board * board, Savegame save);

/* encodes game data from the mine and board structs into the savegame;
   REMEMBER TO FREE saveptr->gameData AFTER CALLING */
int setGameData (Board mines, Board board, Savegame * saveptr);

/* write savegame save to disk */
int writeSaveFile (const char * filename, Savegame save);

/* read savegame from disk into *saveptr;
   REMEMBER TO FREE saveptr->gameData AFTER CALLING */
int loadSaveFile (const char * filename, Savegame * saveptr);

#endif /* SAVEGAME_H */