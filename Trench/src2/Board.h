#pragma once

#include<list>
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
    //Main board
	std::vector<std::vector<Piece> > board;

public:
    //Board constructor, builds board with default positions
	Board();
	//Get all possible moves of a team
	std::list<Move> getAllMoves(Team team);
	//Get all possible moves of a piece
	std::list<Move> getPieceMoves(MCoord x,MCoord y);
    //Get a piece
	Piece getPiece(MCoord x, MCoord y);
	//Get value of a piece
	static int getPieceValue(Piece p);
    //Returns Black if black team won, White if white team won and None if the game hasn't ended
	Team getGameEnded();

    //Moves a piece, returning a new board
	Board movePiece(Move move);
    //Calculates global score based on heuristics.Positive values indicate white team adjantage, while negative indicate black team advantage
	SHeur calculateScore();
};
