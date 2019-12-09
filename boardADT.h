// Solvability of the NxN sliding tile puzzle
//
// boardADT.h
// 
// Nan Wu
//
// Edit date: 2019.06.23
//
// This is the main program that give the answer of whether a 
// Board puzzle is solvable or not. 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX 1024

// renew the struct type Board.
typedef struct boardstruct *Board;

//create and initiate a new board.
Board initiate_board(char *string);

//split function to split the string.
int *split(char *string, char *delim, int index);

//check the validity of a standard board.
bool is_valid_board(Board board);

//check the board length of two boards are equal.
bool equal_length(Board start_board, Board goal_board);

//disorder of tiles
int disorder_of_tiles(int * tiles, int length);

//disorder of board
int disorder_of_board(int * tiles, int length, int size);

//check if the board is solvable.
bool is_solvable_board(Board start_board, Board goal_board);

//release the used memories.
void free_board(Board board);