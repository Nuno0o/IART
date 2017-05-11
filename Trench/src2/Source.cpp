#include "Printer.h"
#include "Board.h"


void listMoves(std::vector<Move> moves) {
	for (int i = 0; i < moves.size(); i++) {
		std::cout << "Move:(" << (int)moves[i].getSX() << "," << (int)moves[i].getSY() << ") to (" << (int)moves[i].getDX() << "," << (int)moves[i].getDY() << ")\n";
	}
}
int main() {
	Board b = Board();
	printBoard(&b);
	std::vector<Move> moves = b.getAllMoves(Black);
	Board b2 = b.movePiece(moves[0]);
	printBoard(&b2);
	
	return 1;
}