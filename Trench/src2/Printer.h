#include <iostream>

#include "Board.h"
//Print board
void printBoard(Board& b);
//Print board and adds a 'P' to blocks where the selected piece can move
void printBoardWithMoves(Board& b, std::list<Move> moves, int sx,int sy);
