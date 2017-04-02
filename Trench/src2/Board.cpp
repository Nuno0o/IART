#include "Board.h"

Board::Board(){
	this->board =
	{
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SRG    ,BLACK|CPT    ,BLACK|LIT    ,BLACK|GEN    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SRG    ,BLACK|CPT    ,BLACK|LIT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SRG    ,BLACK|CPT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SLD    ,BLACK|SRG    },
		{WHITE|SRG    ,WHITE|SLD    ,WHITE|SLD    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|CPT    ,WHITE|SRG    ,WHITE|SLD    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|LIT    ,WHITE|CPT    ,WHITE|SRG    ,WHITE|SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE|GEN    ,WHITE|LIT    ,WHITE|CPT    ,WHITE|SRG    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        }
	};
}

std::vector<Move> Board::allMoves(Team team){
	//List of all moves for the team
	std::vector<Move> ret;
	//Team for bitwise cmp
	Piece pteam;
	switch(team)
	{
		case Black:
			pteam = BLACK;
			break;
		case White:
			pteam = WHITE;
			break;
		default:
			break;
	}
	//Get moves for all pieces in the board
	for(Coord i = 0;i < this->board.size();i++){
		for(Coord j = 0;j < this->board.size();j++){
			std::vector<Move> moves = pieceMoves(pteam,j,i);
			ret.insert(ret.end(),moves.begin(),moves.end());
		}
	}
	return ret;
}

Piece Board::getPiece(Coord x, Coord y) {
	return this->board[y][x];
}
std::vector<Move> Board::pieceMoves(Piece pteam,Coord x,Coord y){
	std::vector<Move> ret;
	//Get piece at coords
	Piece p = board[y][x];
	//Check if the piece's team is the same as the desired
	if(p & pteam == NULL){
		return ret;
	}
	//If it's a soldier
	if(p & SLD){
		
	}else 
	//If it's a seargent
	if(p & SRG){
		
	}else
	//If it's a captain
	if(p & CPT){
			
	}else
	//If it's a lieutenant
	if(p & LIT){
			
	}else
	//If it's a general
	{
		
	}
	return ret;
}

Move::Move(Coord sx,Coord sy,Coord dx,Coord dy){
	this->startX = sx;
	this->startY = sy;
	this->destX = dx;
	this->destY = dy;
}

Coord Move::getSX(){
	return this->startX;
}
Coord Move::getSY(){
	return this->startY;
}

Coord Move::getDX(){
	return this->destX;
}
Coord Move::getDY(){
	return this->destY;
}