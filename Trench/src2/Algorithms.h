#pragma once

#include "Board.h"

class Algorithms {
public:
	//Negamax without alpha beta pruning
	static Board negamaxWithoutABP(Board & b, int depth, Team team);
	static SHeur negamaxWithoutABPAux(Board & b, int depth, Team team);
};