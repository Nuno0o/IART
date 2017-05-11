#include "Algorithms.h"

Move* Algorithms::negamaxWithoutABP(Board * b, int depth, Team team) {
	if (depth < 1) {
		return 0;
	}
	int best = -10000000000;

	std::vector<Move> moves = b->getAllMoves(team);
	for (int i = 0; i < moves.size(); i++) {

	}
}

SScore negamaxWithoutABPAux(Board * b, int depth, Team team) {
	//If at bottom of search tree
	if (depth == 0 /* || game ended */) {
		return team*b->calculateScore();
	}
	//Check which is the next team
	Team nextTeam;
	if (team == Black) {
		nextTeam = White;
	}
	else nextTeam = Black;
	//Best choice
	SScore best = -100000000000;
	//Try all moves
	std::vector<Move> moves = b->getAllMoves(team);
	for (int i = 0; i < moves.size(); i++) {
		SScore next = negamaxWithoutABPAux(&(b->movePiece(moves[i])),depth-1,nextTeam);
		best = std::fmax(best, next);
	}
	return best;
}