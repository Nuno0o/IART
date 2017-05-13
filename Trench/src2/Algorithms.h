#pragma once

#include "Board.h"

class Algorithms {
public:
	//Negamax without alpha beta pruning
	static Board negamaxWithoutABP(Board & b, int depth, Team team);
	static SHeur negamaxWithoutABPAux(Board & b, int depth, Team team);

	//Negamax with alpha beta pruning
	static Board negamaxWithABP(Board & b, int depth, Team team);
	static SHeur negamaxWithABPAux(Board & b, int depth, Team team, int alpha,int beta);
};