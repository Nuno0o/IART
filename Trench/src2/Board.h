#pragma once

#include<vector>

#include "Defines.h"
#include "Piece.h"

class Move {
private:
	MCoord startX;
	MCoord startY;
	MCoord destX;
	MCoord destY;
public:
	//Constructor
	Move(MCoord sx, MCoord sy, MCoord dx, MCoord dy);

	//Get start x
	MCoord getSX();
	//Get start y
	MCoord getSY();
	//Get destiny x
	MCoord getDX();
	//Get destiny y
	MCoord getDY();

	static bool legalAngle(MAngle angle, Piece p);
	static MCoord getAngleX(MAngle angle);
	static MCoord getAngleY(MAngle angle);
	static MLength getMaxLength(Piece p);
};

class Board {
private:
	std::vector<std::vector<Piece>> board;
	
public:
	Board();
	std::vector<Move> getAllMoves(Team team);
	std::vector<Move> getPieceMoves(MCoord x,MCoord y);
	bool checkPieceTeam(Piece pteam,MCoord x,MCoord y);
	Piece getPiece(MCoord x, MCoord y);

	Board movePiece(Move move);

	SScore getScore();
};
