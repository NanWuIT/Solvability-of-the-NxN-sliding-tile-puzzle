// Solvability of the NxN sliding tile puzzle
//
// puzzle.c
// 
// Nan Wu
//
// Edit date: 2019.06.23
//
// This is the main program that give the answer of whether a 
// Board puzzle is solvable or not. 

#include "boardADT.h"

/* The main function including two parts, one part is for checking
whether the board is illegal, if it is not, then return False.
We call it legal_check. While if it is legal, then using the puzzle
solving function which is with_answer to check whether this question
could be solve.
*/

int main(int argc, char **argv) {

	/* At the beginning, read the stdin, and save the start and goal
	lines, then print it out. ?????????????????????????????
	*/
	char* line1 = malloc(sizeof(char) * SIZE);
	char* line2 = malloc(sizeof(char) * SIZE);
	fgets(line1, SIZE, stdin);
	fgets(line2, SIZE, stdin);
	printf("start: %s\n", line1);
	printf("goal: %s\n", line2);

	Board start = createBoard(line1);
	Board goal = createBoard(line2);

	/*
	Checking whether the input is legal, firstly. Then checking whether
	legal board is solvable.
	*/
	if (inputError(start) || inputError(goal) ||
		size(start) != size(goal) || sum(start) != sum(goal)) {
		printf("Sorry, NxN Board required. \n");
		return EXIT_FAILURE;
	}
	else {

		if (!(solvable(start, goal))) {
			printf("unsolvable\n");
		}
		else {
			printf("solvable\n");
		}

	}

	// In the end, we should free all the memories ?????????
	free(start);
	free(goal);
	free(line1);
	free(line2);

	// return success. 
	return EXIT_SUCCESS;
}