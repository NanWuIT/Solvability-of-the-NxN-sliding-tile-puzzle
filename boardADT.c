// Solvability of the NxN sliding tile puzzle
//
// boardADT.c
// 
// Nan Wu
//
// Edit date: 2019.06.23
//
// This is the main program that give the answer of whether a 
// Board puzzle is solvable or not. 
#include "boardADT.h"

//struct board defined.
struct boardstruct {
	//board length and size.
	int length, size;
	int * tiles;
};

/*board creat and initiate, use function split.
	intput the start and goal board, initiate them.
	return the board*/
Board initiate_board(char *string) {
	Board board = malloc(sizeof(struct boardstruct));
	if (board != NULL) {
		board->length = 0;
		board->size = 0;
		//board->tiles = NULL;
		board->tiles = malloc(sizeof(int) * MAX);
		//char *string need to be initiated by function memset(string, '\0', sizeof(char) * 1024)~
		board->tiles = split(string, " ", 0);
		int i;
		for (i = 0; *(board->tiles + i) >= 0; ++i);
		board->length = i;
		board->size = (int)sqrt((double)board->length);
	}
	return board;
}
 
/*split the input string and split the strings by 
	cutting the spaces in the strings.
	@param string, deliminator and index.
	return result.*/
int * split(char *string, char *delim, int index) {
	int *result = malloc(sizeof(char) * MAX);
	if ((string == NULL) || (strlen(string) == 0)) {
		return NULL;
	}
	if ((delim == NULL) || (strlen(delim) == 0)) {
		return NULL;
	}
	char *tmp = strtok(string, delim);
	while (tmp != NULL) {
		if (strcmp(tmp, "b") == 0) {
			*(result + index) = 0;
		}
		*(result + index) = atoi(tmp);
		tmp = strtok(NULL, " ");
		index++;
	}
	return result;
}

/*check the validity of boards.
	check the board is not NULL, length, size
	and the consecutive and non-duplicate numbers.
	return true or false.*/
bool is_valid_board(Board board) {
	if ((board == NULL) || (board->length == 0) || (board->tiles == NULL)) {
		return false;
	}
	if ((board->length < 4) || (board->size < 2)) {
		return false;
	}
	if (board->length != board->size * board->size) {
		return false;
	}
	int i = 0;
	while (i < board->length) {
		bool result = false;
		for (int j = 0; j < board->length; j++) {
			if (*(board->tiles + j) == i) {
				result = true;
				break;
			}
		}
		if (result == false) {
			return false;
		}
		i++;
	}
	return true;
}

/*check if the length of two boards are equal.
	@param start and goal board.
	return true or false.*/
bool equal_length(Board start_board, Board goal_board) {
	if (start_board->length == goal_board->length) {
		return true;
	}
	return false;
}

/*the disorder of the every tiles,
	sum of disorders.
	@param tiles and length.
	return int diorder of tiles.*/
int disorder_of_tiles(int * tiles, int length) {
	int tile_disorder = 0;
	for (int i = 0; i < length; i++) {
		if (*(tiles + i) != 0) {
			for (int j = i + 1; j < length; j++) {
				if (*(tiles + j) != 0) {
					tile_disorder += (*(tiles + i) > *(tiles + j));
				}
			}
		}
	}
	return tile_disorder;
}

/*disorder of tiles plus the nb of line
	which holds a blank in the even size of board.
	@param tiles, length and size.
	return int diorder of board.*/
int disorder_of_board(int * tiles, int length, int size) {
	int board_disorder = 0;
	for (int i = 0; i < length; i++) {
		if (*(tiles + i) == 0) {
			if ((size % 2) == 0) {
				board_disorder = disorder_of_tiles(tiles, length) + ((i / size) + 1);
			}
			else {
				board_disorder = disorder_of_tiles(tiles, length);
			}
		}
	}
	return board_disorder;
}

/*check the parity of start board and goal board.
	return true or false.*/
bool is_solvable_board(Board start_board, Board goal_board) {
	if (disorder_of_board(start_board->tiles, start_board->length, start_board->size) % 2 
		== disorder_of_board(goal_board->tiles, goal_board->length, goal_board->size) % 2)
	{
		return true;
	}
	return false;
}

/*release the used memories of board.
	return void.*/
void free_board(Board board) {
	if (board != NULL) {
		if (board->tiles != NULL) {
			free(board->tiles);
		}
		free(board);
	}
}