#include "Printer.h"
#include "Board.h"

int main() {
	Board b = Board();
	printBoard(&b);
	std::vector<Move> moves = b.getAllMoves(Black);
	for (int i = 0; i < moves.size(); i++) {
		std::cout << "Move:(" << (int)moves[i].getSX() << "," << (int)moves[i].getSY() << ") to (" << (int)moves[i].getDX() << "," << (int)moves[i].getDY() << ")\n";
	}
	return 1;
}