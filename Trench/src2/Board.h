#pragma once

#include<vector>

#include "Defines.h"
#include "Piece.h"

class Board {
private:
	std::vector<std::vector<Piece>> board;
	
public:
	Board();
	vector<Move> allMoves(Team team);
	vector<Move> pieceMoves(Piece pteam,Coord x,Coord y);
};

class Move {
private:
	Coord startX;
	Coord startY;
	Coord destX;
	Coord destY;
public:
	//Constructor
	Move(Coord sx, Coord sy, Coord dx, Coord dy);
	
	//Get start x
	Coord getSX();
	//Get start y
	Coord getSY();
	//Get destiny x
	Coord getDX();
	//Get destiny y
	Coord getDY();
}