# Solvability-of-the-NxN-sliding-tile-puzzle
The sliding tile puzzle is a game that requires you to move tiles on a board. The board is NxN, and there are N-1 tiles numbered from 1..N-1 that occupy the board. There is hence 1 location on the board that is empty (referred to as a blank). 

There is some (arbitrary) start configuration of the numbered tiles on the board. Starting with this configuration, the aim is to move tiles until some chosen goal configuration is reached, and to do this in the least possible number of moves. You may only move a tile into the blank if the tile neighbours the blank. Moves can be only be in the horizontal and vertical directions (not diagonal). 

The sliding-tile puzzle also has other names, such as the 8 Puzzle (for the special case of a 3x3 board) or 15 Puzzle (a 4x4 board) and so on. Sometimes the name N Puzzle is used (indicating an NxN board).

You can play the 15 puzzle game online at:

[15 sliding-tile puzzle](http://lorecioni.github.io/fifteen-puzzle-game/)

For this puzzle game,  the program reads text from stdin as the format below. 
```
9 12 5 4 2 b 7 11 3 6 10 13 14 1 8 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 b 15
```

This program would give the result as
```
start: 9 12 5 4 2 b 7 11 3 6 10 13 14 1 8 15
goal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 b 15
solvable
```
or
```
start: 2 1 3 b
goal: 1 2 3 b
unsolvable
```
