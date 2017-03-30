#pragma once

typedef unsigned long long U64;

#define C64(constantU64) constantU64##ULL


// A Bitboard represents game state.
//
// We use a little-endian mapping of bits to rank-and-file coordinates. For
// an 8x8 board, this mapping looks like:
//
//  8 | 56 57 58 59 60 61 62 63
//  7 | 48 49 50 51 52 53 54 55
//  6 | 40 41 42 43 44 45 46 47
//  5 | 32 33 34 35 36 37 38 39
//  4 | 24 25 26 27 28 29 30 31
//  3 | 16 17 18 19 20 21 22 23
//  2 | 8  9  10 11 12 13 14 15
//  1 | 0  1  2  3  4  5  6  7
//    -------------------------
//      a  b  c  d  e  f  g  h
//
//  STARTING BOARD
//  8 | GE LI CA SA 60 61 62 63
//  7 | LI CA SA SO 52 53 54 55
//  6 | CA SA SO SO 44 45 46 47
//  5 | SA SO SO SO 36 37 38 39
//  4 | 24 25 26 27 SO SO SO SA
//  3 | 16 17 18 19 SO SO SA CA
//  2 | 8  9  10 11 SO SA CA LI
//  1 | 0  1  2  3  SA CA LI GE
//    -------------------------
//      a  b  c  d  e  f  g  h
//
// Coordinates
class BitBoard {
private:
	U64 whiteSoldiers;
	U64 whiteSargents;
	U64 whiteCaptains;
	U64 whiteLieutenants;
	U64 whiteGeneral;

	U64 blackSoldiers;
	U64 blackSargents;
	U64 blackCaptains;
	U64 blackLieutenants;
	U64 blackGeneral;
public:
	//Initialize board
	BitBoard();
};