#include "Printer.h"
#include "Board.h"
#include "Interface.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void listMoves(std::vector<Move> moves) {
	for (int i = 0; i < moves.size(); i++) {
		std::cout << "Move:(" << (int)moves[i].getSX() << "," << (int)moves[i].getSY() << ") to (" << (int)moves[i].getDX() << "," << (int)moves[i].getDY() << ")\n";
	}
}
int main() {
	srand(time(0));
	Interface();
    return 0;
	//Board b = Board();
	//printBoard(b);
	//listMoves(b.getAllMoves(White));
	//listMoves(b.getAllMoves(Black));
	//Board b2 = Algorithms::negamaxWithoutABP(b,3,White);
	//Board b2 = b.movePiece(b.getAllMoves(Black)[6]);
	//printBoard(b2);

}
