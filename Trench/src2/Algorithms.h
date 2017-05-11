#pragma once

#include "Board.h"

class Algorithms {
public:
	//Negamax without alpha beta pruning
	Move * negamaxWithoutABP(Board * b, int depth, Team team);
};