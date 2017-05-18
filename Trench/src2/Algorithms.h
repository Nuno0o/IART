#pragma once

#include "Board.h"

class Algorithms {
public:
    //Negamax
	static Board negamax(Board & b, int depth, Team team,bool alphabeta);
	//Negamax without alpha beta pruning
	static SHeur negamaxWithoutABP(Board & b, int depth, Team team);
	//Negamax with alpha beta pruning
	static SHeur negamaxWithABP(Board & b, int depth, Team team, int alpha,int beta);
};
