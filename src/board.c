/* board.c
   defines utility functions for board memory management */

#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* memset */

#include "board.h"

int initBoardArray (Board * board) {
    board->array = (unsigned char **) malloc ((board->width + 2) * sizeof (unsigned char *));
	for (int i = 0; i < board->width + 2; i++) {
		board->array[i] = (unsigned char *) malloc (board->height + 2);
        memset (board->array[i], '+', board->height + 2);
    }
    return 0;
}

int freeBoardArray (Board * board) {
    for (int i = 0; i < board->width + 2; i++)
        free (board->array[i]);
    free (board->array);
    return 0;
}