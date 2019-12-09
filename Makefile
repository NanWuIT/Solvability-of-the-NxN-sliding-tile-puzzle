# COMP9024 Assignment1
#
# Solvability of the NxN sliding tile puzzle
#
# Makefile
# 
# Nan Wu
#
# Edit date: 2019.06.23

all: puzzle

puzzle: boardADT.o puzzle.o

boardADT.o: boardADT.c boardADT.h
	gcc -c boardADT.c

puzzle.o: puzzle.c boardADT.h
	gcc -c puzzle.c 

clean:
	rm -f puzzle *.o core *.gch



