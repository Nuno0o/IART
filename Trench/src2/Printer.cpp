#include "Printer.h"

void printBoard(Board& b) {
	std::cout << " |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n";
	std::cout << "-+-----+-----+-----+-----+-----+-----+-----+-----+\n";
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << " |";
		for (int j = 0; j < BOARD_SIZE; j++) {
			Piece p = b.getPiece(i, j);
			if (i == j) {
				std::cout << "\\ ";
			}else
			std::cout << "  ";
			if (p & BLACK) {
				std::cout << "B  |";
			}
			else if (p & WHITE) {
				std::cout << "W  |";
			}
			else std::cout << "   |";
		}
		std::cout << "\n";
		std::cout << i <<"|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			Piece p = b.getPiece(i, j);
			if (p & EMPTY) {
				if (i == j) {
					std::cout << "  \\  ";
				}
				else
					std::cout << "     ";
			}

			if (p & SLD) {
				std::cout << " SLD ";
			}
			else if (p & SRG) {
				std::cout << " SRG ";
			}
			else if (p & CPT) {
				std::cout << " CPT ";
			}
			else if (p & LIT) {
				std::cout << " LIT ";
			}
			else if (p & GEN) {
				std::cout << " GEN ";
			}
			std::cout << "|";
		}
		std::cout << "\n";
		std::cout << " |";
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == j) {
				std::cout << "    \\|";
			}
			else
				std::cout << "     |";
		}
		std::cout << "\n";
		std::cout << "-+";
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << "-----";
			std::cout << "+";
		}
		std::cout << "\n";
	}
}

void printBoardWithMoves(Board& b, std::list<Move> moves,int sx, int sy) {
	std::cout << " |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |\n";
	std::cout << "-+-----+-----+-----+-----+-----+-----+-----+-----+\n";
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << " |";
		for (int j = 0; j < BOARD_SIZE; j++) {
			Piece p = b.getPiece(i, j);
			if (i == j) {
				std::cout << "\\ ";
			}else
			std::cout << "  ";
			if (p & BLACK) {
				std::cout << "B  |";
			}
			else if (p & WHITE) {
				std::cout << "W  |";
			}
			else std::cout << "   |";
		}
		std::cout << "\n";
		std::cout << i <<"|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			Piece p = b.getPiece(i, j);
			if (p & EMPTY) {
				if (i == j) {
					std::cout << "  \\  ";
				}
				else
					std::cout << "     ";
			}

			if (p & SLD) {
				std::cout << " SLD ";
			}
			else if (p & SRG) {
				std::cout << " SRG ";
			}
			else if (p & CPT) {
				std::cout << " CPT ";
			}
			else if (p & LIT) {
				std::cout << " LIT ";
			}
			else if (p & GEN) {
				std::cout << " GEN ";
			}
			std::cout << "|";
		}
		std::cout << "\n";
		std::cout << " |";
		for (int j = 0; j < BOARD_SIZE; j++) {
            bool possibleTarget = false;
		    for(auto it = moves.begin(); it != moves.end();it++){
                if((*it).getDX() == j && (*it).getDY() == i && (*it).getSX() == sx && (*it).getSY() == sy){
                    possibleTarget = true;
                    break;
                }
		    }
			if (i == j) {
                if(possibleTarget){
                    std::cout << "  P \\|";
                }else
				std::cout << "    \\|";
			}
			else{
                if(possibleTarget){
                    std::cout << "  P  |";
                }else std::cout << "     |";
			}

		}
		std::cout << "\n";
		std::cout << "-+";
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << "-----";
			std::cout << "+";
		}
		std::cout << "\n";
	}
}
