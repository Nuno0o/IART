#include <Windows.h>

#include "Printer.h"

void printBoard(Board* b) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (COLOR_DARKGRAY << 4) | COLOR_BLACK);
	std::cout << "\\-----+-----+-----+-----+-----+-----+-----+-----+";
	std::cout << "\n";
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << "|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == j) {
				std::cout << "\\    |";
			}else
			std::cout << "     |";
		}
		std::cout << "\n";
		std::cout << "|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			Piece p = b->getPiece(i, j);
			if (p & EMPTY) {
				if (i == j) {
					std::cout << "  \\  ";
				}
				else
					std::cout << "     ";
			}
			if (p & BLACK) {
				SetConsoleTextAttribute(console, (COLOR_DARKGRAY << 4) | COLOR_BLACK);
			}
			else if (p & WHITE) {
				SetConsoleTextAttribute(console, (COLOR_DARKGRAY << 4) | COLOR_WHITE);
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
			SetConsoleTextAttribute(console, (COLOR_DARKGRAY << 4) | COLOR_BLACK);
			std::cout << "|";
		}
		std::cout << "\n";
		std::cout << "|";
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == j) {
				std::cout << "    \\|";
			}
			else
				std::cout << "     |";
		}
		std::cout << "\n";
		std::cout << "+";
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << "-----";
			if (j == i) {
				std::cout << "\\";
			}
			else std::cout << "+";
		}
		std::cout << "\n";
	}
}