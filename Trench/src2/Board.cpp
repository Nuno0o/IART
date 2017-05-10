#include "Board.h"

Board::Board() {
	this->board =
	{
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK | SRG    ,BLACK | CPT    ,BLACK | LIT    ,BLACK | GEN    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK | SLD    ,BLACK | SRG    ,BLACK | CPT    ,BLACK | LIT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK | SLD    ,BLACK | SLD    ,BLACK | SRG    ,BLACK | CPT    },
		{EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        ,BLACK | SLD    ,BLACK | SLD    ,BLACK | SLD    ,BLACK | SRG    },
		{WHITE | SRG    ,WHITE | SLD    ,WHITE | SLD    ,WHITE | SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE | CPT    ,WHITE | SRG    ,WHITE | SLD    ,WHITE | SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE | LIT    ,WHITE | CPT    ,WHITE | SRG    ,WHITE | SLD    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        },
		{WHITE | GEN    ,WHITE | LIT    ,WHITE | CPT    ,WHITE | SRG    ,EMPTY        ,EMPTY        ,EMPTY        ,EMPTY        }
	};
}

std::vector<Move> Board::getAllMoves(Team team) {
	//List of all moves for the team
	std::vector<Move> ret;
	//Team for bitwise cmp
	Piece pteam;
	switch (team)
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
	for (MCoord i = 0; i < this->board.size(); i++) {
		for (MCoord j = 0; j < this->board.size(); j++) {
			if (checkPieceTeam(pteam, j, i)) {
				std::vector<Move> moves = getPieceMoves(j, i);
				ret.insert(ret.end(), moves.begin(), moves.end());
			}
		}
	}
	return ret;
}


bool Board::checkPieceTeam(Piece pteam, MCoord x, MCoord y) {
	//Get piece at coords
	Piece p = board[y][x];
	//Check if the piece's team is the same as the desired
	if (p & pteam == NULL) {
		return false;
	}
	else return true;
}

std::vector<Move> Board::getPieceMoves(MCoord x, MCoord y) {
	std::vector<Move> ret;
	//Get piece at coords
	Piece p = board[y][x];
	bool atTrench = x == y;
	bool atFriendlyTerritory = (p & BLACK && x > y) || (p & WHITE && x < y);
	MLength maxLength = Move::getMaxLength(p);

	
	for (MAngle angles = 0; angles < 8; angles++) {
		for (MLength length = 0; length < maxLength; length++) {
			if (Move::legalAngle(angles, p)) {
				MCoord ydest = y + Move::getAngleY(angles);
				MCoord xdest = x + Move::getAngleX(angles);
				if (ydest < 0 || xdest < 0 || ydest > 7 || xdest > 7) {
					continue;
				}
				Piece p2 = board[ydest][xdest];
				//If it's a soldier
				if (p & SLD) {

				}
				else
				//If it's a seargent
				if (p & SRG) {

				}
				else
				//If it's a captain
				if (p & CPT) {
						
				}
				else
				//If it's a lieutenant
				if (p & LIT) {

				}
				else
				//If it's a general
				if (p & GEN)
				{

				}

			}
		}
	}
	return ret;
}

////////////////////////////// MOVE ///////////////////////////////

Move::Move(MCoord sx, MCoord sy, MCoord dx, MCoord dy) {
	this->startX = sx;
	this->startY = sy;
	this->destX = dx;
	this->destY = dy;
}

MCoord Move::getSX() {
	return this->startX;
}

MCoord Move::getSY() {
	return this->startY;
}

MCoord Move::getDX() {
	return this->destX;
}

MCoord Move::getDY() {
	return this->destY;
}

Piece Board::getPiece(MCoord y, MCoord x) {
	return this->board[y][x];
}

/////////////////////////////// ANGLE ////////////////////////////////

MCoord Move::getAngleX(MAngle angle) {
	if (angle == 0 || angle == 1 || angle == 7) {
		return 1;
	}
	if (angle == 2 || angle == 6) {
		return 0;
	}
	else return -1;
}

MCoord Move::getAngleY(MAngle angle) {
	if (angle == 1 || angle == 2 || angle == 3) {
		return 1;
	}
	if (angle == 0 || angle == 4) {
		return 0;
	}
	else return -1;
}

bool Move::legalAngle(MAngle angle, Piece p) {
	if (p & SLD) {
		if (angle % 2 == 0)
			return true;
		else return false;
	}
	else
		if (p & SRG) {
			if (p & BLACK) {
				if (angle == 7 || angle == 1 || angle == 5)
					return false;
				else return true;
			}
			else if (p & WHITE) {
				if (angle == 3 || angle == 1 || angle == 5)
					return false;
				else return true;
			}
		}
		else
			if (p & CPT) {
				if (angle == 1 || angle == 5)
					return false;
				else return true;
			}
			else
				if (p & LIT) {
					if (p & BLACK) {
						if (angle == 7)
							return false;
						else return true;
					}
					else if (p & WHITE) {
						if (angle == 3) {
							return false;
						}
						else return true;
					}
				}
				else return true;
}

MLength Move::getMaxLength(Piece p) {
	//If it's a soldie
	if (p & SLD) {
		return 1;
	}
	else
		//If it's a seargent
		if (p & SRG) {
			return 2;
		}
		else
			//If it's a captain
			if (p & CPT) {
				return 3;
			}
			else
				//If it's a lieutenant
				if (p & LIT) {
					return 4;
				}
				else
					//If it's a general
					if (p & GEN)
					{
						return 5;
					}
	//Empty
	return 0;
}