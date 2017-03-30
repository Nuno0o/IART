#include "Board.h"
#include <cmath>

BitBoard::BitBoard() {
	
	//White pieces
	this->whiteSoldiers = (1 << 51) + (1 << 43) + (1 << 35) + (1 << 42) + (1 << 34) + (1 << 33);
	this->whiteSargents = (1 << 59) + (1 << 50) + (1 << 41) + (1 << 32);
	this->whiteCaptains = (1 << 58) + (1 << 49) + (1 << 40);
	this->whiteLieutenants = (1 << 57) + (1 << 48);
	this->whiteGeneral = (1 << 56);

	//Black pieces
	this->blackSoldiers = (1 << 12) + (1 << 20) + (1 << 28) + (1 << 21) + (1 << 29) + (1 << 38);
	this->blackSargents = (1 << 4) + (1 << 13) + (1 << 22) + (1 << 31);
	this->blackCaptains = (1 << 5) + (1 << 14) + (1 << 23);
	this->blackLieutenants = (1 << 6) + (1 << 15);
	this->blackGeneral = (1 << 7);
}

U64 BitBoard::getMoveSet(unsigned int x, unsigned int y) {
	U64 allWhites = this->whiteSoldiers & this->whiteSargents & this->whiteCaptains & this->whiteLieutenants & this->whiteGeneral;
	U64 allBlacks = this->blackSoldiers & this->blackSargents & this->blackCaptains & this->blackLieutenants & this->blackGeneral;
	
	U64 pieceToMove = pow(2, x - 1 + 7 * (y - 1));
	return allWhites;
}