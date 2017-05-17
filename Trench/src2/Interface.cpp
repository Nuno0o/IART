#include "Interface.h"
#include "Printer.h"
#include "Algorithms.h"
#include <iostream>
Interface::Interface() {
	std::cout << "Welcome to trench!\n\n";
	PlayerSettings p1;
	PlayerSettings p2;

	for (int i = 1; i < 3; i++) {
		std::cout << "What type of player is player " << i << " ?\n1-human\n2-computer(minimax)\n3-computer(minimax with pruning)\n>>";
		int type;
		std::cin >> type;
		PlayerSettings player;
		if (type == 1) {
			player = PlayerSettings();
		}
		else if (type == 2) {
			int depth = 1;
			std::cout << "What is the depth of the search tree desired?";
			std::cin >> depth;
			player = PlayerSettings(MinMax, depth);
		}
		else if (type == 3) {
			int depth = 1;
			std::cout << "What is the depth of the search tree desired?";
			std::cin >> depth;
			player = PlayerSettings(MinMaxAB, depth);
		}
		if (i == 1) {
			p1 = player;
		}
		else p2 = player;
	}

	this->game = Game(p1,p2);

	this->Play();
}

void Interface::Play() {
	std::cout << "\nGame is starting...\n";
	Team turn = White;
	Team won = None;
	while (won == None) {
		//Retrieve player settings for player
		PlayerSettings p;

		printBoard(game.board);
		if (turn == White) {
			std::cout << "\nWhite turn\n";
			p = game.player1;
		}
		else {
			std::cout << "\nBlack turn\n";
			p = game.player2;
		}
		//If the player is human
		if (p.type == Human) {
			int sx, sy, dx, dy;
			std::cout << "Insert X of the piece you want to move\n>>";
			std::cin >> sx;
			std::cout << "Insert Y of the piece you want to move\n>>";
			std::cin >> sy;
			std::cout << "Insert X of the destiny of the piece you want to move\n>>";
			std::cin >> dx;
			std::cout << "Insert Y of the destiny of the piece you want to move\n>>";
			std::cin >> dy;

			std::list<Move> moves = game.board.getAllMoves(turn);

			Move* validMove = NULL;
			for (auto it = moves.begin(); it != moves.end();it++) {
				if ((*it).getSX() == sx && (*it).getSY() == sy && (*it).getDX() == dx && (*it).getDY() == dy) {
					validMove = &(*it);
				}
			}
			if (validMove != NULL) {
				game.board = game.board.movePiece(*validMove);
			}
			else {
				std::cout << "Invalid move, try again\n";
				continue;
			}
		}
		else if (p.type == MinMax) {
			game.board = Algorithms::negamaxWithoutABP(game.board, p.depth, turn);
		}
		else if (p.type == MinMaxAB) {
			game.board = Algorithms::negamaxWithABP(game.board, p.depth, turn);
		}
		if (turn == White) {
			turn = Black;
		}
		else turn = White;
		won = game.board.getGameEnded();
	}
	if (won == Black) {
		std::cout << "\nBlack won\n";
	}
	else if (won == White) {
		std::cout << "\nWhite won\n";
	}
}
