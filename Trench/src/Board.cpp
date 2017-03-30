#include "Board.h"
#include "Defines.h"
#include <cmath>

BitBoard::BitBoard() {
	
	//White pieces
	this->whiteSoldiers = shift(51) + shift(43) + shift(35) + shift(42) + shift(34) + shift(33);
	this->whiteSargents = shift(59) + shift(50) + shift(41) + shift(32);
	this->whiteCaptains = shift(58) + shift(49) + shift(40);
	this->whiteLieutenants = shift(57) + shift(48);
	this->whiteGeneral = shift(56);

	//Black pieces
	this->blackSoldiers = shift(12) + shift(20) + shift(28) + shift(21) + shift(29) + shift(38);
	this->blackSargents = shift(4) + shift(13) + shift(22) + shift(31);
	this->blackCaptains = shift(5) + shift(14) + shift(23);
	this->blackLieutenants = shift(6) + shift(15);
	this->blackGeneral = shift(7);
}

U64 BitBoard::getMoveSet(unsigned int x, unsigned int y) {
	U64 allWhites = this->whiteSoldiers & this->whiteSargents & this->whiteCaptains & this->whiteLieutenants & this->whiteGeneral;
	U64 allBlacks = this->blackSoldiers & this->blackSargents & this->blackCaptains & this->blackLieutenants & this->blackGeneral;
	
	U64 pieceToMove = shift((x - 1) + (8 * (y - 1)));
	return allWhites;
}