#include "Board.h"
#include <iostream>
Board::Board() {
	board =
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
			if (pteam & board[i][j]) {
				std::vector<Move> moves = getPieceMoves(j, i);
				ret.insert(ret.end(), moves.begin(), moves.end());
			}
		}
	}
	return ret;
}



std::vector<Move> Board::getPieceMoves(MCoord x, MCoord y) {
	std::vector<Move> ret;
	//Get piece at coords
	Piece p = board[y][x];
	//Checks if piece is at the trench
	bool atTrench = x == y;
	//Checks if piece is in it's territory(not used if in trench)
	bool atFriendlyTerritory = (p & BLACK && x > y) || (p & WHITE && x < y);
	//Length the piece can move
	MLength maxLength = Move::getMaxLength(p);

	
	for (MAngle angles = 0; angles < 8; angles++) {
		for (MLength length = 1; length <= maxLength; length++) {
			if (Move::legalAngle(angles, p)) {
				//Get destiny coords
				MCoord ydest = y + Move::getAngleY(angles)*length;
				MCoord xdest = x + Move::getAngleX(angles)*length;
				//Check if outside boundaries
				if (ydest < 0 || xdest < 0 || ydest > 7 || xdest > 7) {
					continue;
				}
				//Get destiny
				Piece p2 = board[ydest][xdest];
				//If destiny is empty
				if (p2 & EMPTY) {
					Move move = Move(x, y, xdest, ydest);
					ret.push_back(move);
					continue;
				}
				//If destiny is friend
				else if (p & BLACK && p2 & BLACK || p & WHITE && p2 & WHITE) {
					break;
				}
				//If destiny is enemy
				else{
					//If both target and origin are trench
					if (atTrench && xdest == ydest) {
						break;
					}
					//If target is in enemy field and current in trench
					else if (atTrench && (p & BLACK && xdest < ydest) || (p & WHITE && xdest > ydest)) {
						Move move = Move(x, y, xdest, ydest);
						ret.push_back(move);
						//Continue pois pode comer mais pe�as na mesma linha caso esteja na trincheira
						continue;
					}
					//If target is in ally field and current in trench
					else if (atTrench && (p & BLACK && xdest > ydest) || (p & WHITE && xdest < ydest)) {
						break;
					}
					else if (!atTrench && xdest == ydest && atFriendlyTerritory) {
						if (atFriendlyTerritory) {
							break;
						}
						else {
							Move move = Move(x, y, xdest, ydest);
							ret.push_back(move);
							break;
						}
					}
					else if (!atTrench && xdest != ydest) {
						Move move = Move(x, y, xdest, ydest);
						ret.push_back(move);
						break;
					}
				}
			}
		}
	}
	return ret;
}

int Board::getTeamScore(Team team) {
	Piece enemyTeam;
	if (team == Black) {
		enemyTeam = WHITE;
	}
	else enemyTeam = BLACK;

	int total = 36;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] & enemyTeam) {
				total -= getPieceValue(board[i][j]);
			}
		}
	}
	return total;
}

bool Board::getGameEnded() {
	return getTeamScore(Black) == 36 || getTeamScore(White) == 36;
}

Board Board::movePiece(Move move) {
	Board b = Board();
	b.board = this->board;
	b.board[move.getDY()][move.getDX()] = b.board[move.getSY()][move.getSX()];
	b.board[move.getSY()][move.getSX()] = EMPTY;
	return b;
}

SHeur Board::calculateScore(Team team) {
	return 0;
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

int Board::getPieceValue(Piece p) {
	Piece paux = p;
	for (int i = 1; i < 6; paux >>= 1,i++) {
		if (paux & 1) {
			return i;
		}
	}
	return -1;
}

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
	//If it's a soldier
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
