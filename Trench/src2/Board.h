#pragma once

#include<vector>

#include "Defines.h"
#include "Piece.h"

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
};

class Board {
private:
	std::vector<std::vector<Piece>> board;
	
public:
	Board();
	std::vector<Move> allMoves(Team team);
	std::vector<Move> pieceMoves(Piece pteam,Coord x,Coord y);
	Piece getPiece(Coord x, Coord y);
};