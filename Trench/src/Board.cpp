#include "Board.h"
#include <cmath>

BitBoard::BitBoard() {
	//White pieces
	this->whiteSoldiers = pow(2, 51) + pow(2, 43) + pow(2, 35) + pow(2, 42) + pow(2, 34) + pow(2, 33);
	this->whiteSargents = pow(2, 59) + pow(2, 50) + pow(2, 41) + pow(2, 32);
	this->whiteCaptains = pow(2, 58) + pow(2, 49) + pow(2, 40);
	this->whiteLieutenants = pow(2, 57) + pow(2, 48);
	this->whiteGeneral = pow(2, 56);

	//Black pieces
	this->blackSoldiers = pow(2, 12) + pow(2, 20) + pow(2, 28) + pow(2, 21) + pow(2, 29) + pow(2, 38);
	this->blackSargents = pow(2, 4) + pow(2, 13) + pow(2, 22) + pow(2, 31);
	this->blackCaptains = pow(2, 5) + pow(2, 14) + pow(2, 23);
	this->blackLieutenants = pow(2, 6) + pow(2, 15);
	this->blackGeneral = pow(2, 7);
}