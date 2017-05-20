#include "Interface.h"
#include "Printer.h"
#include "Algorithms.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
//Read int from std::cin
int getInt(){
    int x;
    std::cout<< ">>";
    while(!(std::cin >> x)){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "\nNot an integer, try again.\n>>";
    }
    return x;
}
Interface::Interface() {
	std::cout << "Welcome to trench!\n\n";
	PlayerSettings p1;
	PlayerSettings p2;

	for (int i = 1; i < 3; i++) {
		std::cout << "What type of player is player " << i << " ?\n1-human\n2-computer(minimax)\n3-computer(minimax with pruning)\n";
		int type;
		type = getInt();
		PlayerSettings player;
		if (type == 1) {
			player = PlayerSettings();
		}
		else if (type == 2) {
			int depth = 1;
			std::cout << "What is the depth of the search tree desired?\n";
			depth = getInt();
			player = PlayerSettings(MinMax, depth);
		}
		else if (type == 3) {
			int depth = 1;
			std::cout << "What is the depth of the search tree desired?\n";
			depth = getInt();
			player = PlayerSettings(MinMaxAB, depth);
		}
		if (i == 1) {
			p1 = player;
		}
		else p2 = player;
	}
	std::cout << "Save logs to file?\n";

	bool logs = getInt();

	this->game = Game(p1,p2);
	this->logs = logs;
    if(logs){
        clearLog();
    }
	this->Play();
}

void Interface::Play() {
    //Print game is starting
	std::cout << "\nGame is starting...\n";
	Team turn = White;
	Team won = None;

	//Log times
	std::vector<double> whiteTimes;
	std::vector<double> blackTimes;

	int currTurn = 1;

	while (won == None) {
		//Retrieve player settings for player
		PlayerSettings p;

		printBoard(game.board);
		if (turn == White) {
			std::cout << "\nWhite turn " << currTurn << "\n";
			p = game.player1;
		}
		else {
			std::cout << "\nBlack turn " << currTurn << "\n";
			p = game.player2;
		}
		//If the player is human
		if (p.type == Human) {
			int sx, sy, dx, dy;
			std::cout << "Insert X of the piece you want to move\n";
			sx = getInt();
			std::cout << "Insert Y of the piece you want to move\n";
			sy = getInt();
			std::cout << "Insert X of the destiny of the piece you want to move\n";
			dx = getInt();
			std::cout << "Insert Y of the destiny of the piece you want to move\n";
			dy = getInt();

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
				std::cout << "Invalid move, try again\n\n";
				continue;
			}
			if(this->logs){
                printToLog(turn,*validMove,0);
                if(turn == White){
                    whiteTimes.push_back(0);
                }else blackTimes.push_back(0);
            }
		}
		else if (p.type == MinMax) {
            auto t_start = std::chrono::high_resolution_clock::now();
			Move thismove = Algorithms::negamax(game.board, p.depth, turn, false);
            auto t_end = std::chrono::high_resolution_clock::now();
            std::cout << "Time taken: " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << "ms\n";
            game.board = game.board.movePiece(thismove);
            if(this->logs){
                printToLog(turn,thismove,std::chrono::duration<double, std::milli>(t_end-t_start).count());
                if(turn == White){
                    whiteTimes.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
                }else blackTimes.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
            }
		}
		else if (p.type == MinMaxAB) {
            auto t_start = std::chrono::high_resolution_clock::now();
			Move thismove = Algorithms::negamax(game.board, p.depth, turn,true);
            auto t_end = std::chrono::high_resolution_clock::now();
            std::cout << "Time taken: " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << "ms\n";
            game.board = game.board.movePiece(thismove);
            if(this->logs){
                printToLog(turn,thismove,std::chrono::duration<double, std::milli>(t_end-t_start).count());
                if(turn == White){
                    whiteTimes.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
                }else blackTimes.push_back(std::chrono::duration<double, std::milli>(t_end-t_start).count());
            }
		}

		if (turn == White) {
			turn = Black;
		}
		else turn = White;
		won = game.board.getGameEnded();
		currTurn++;
	}
	if (won == Black) {
		std::cout << "\nBlack won\n";
	}
	else if (won == White) {
		std::cout << "\nWhite won\n";
	}
	if(this->logs){
        printEndGame(won,currTurn,std::accumulate(whiteTimes.begin(),whiteTimes.end(),0.0) / whiteTimes.size(), std::accumulate(blackTimes.begin(),blackTimes.end(),0.0) / blackTimes.size());
	}
}
void Interface::clearLog(){
    std::ofstream ofs;
    ofs.open("logs.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void Interface::printToLog(Team team,Move mov,double time){
    std::string s;
    PlayerType p;
    int depth;
    if(team == Black){
        s = "Black";
        p = this->game.player2.type;
        if(p != Human){
            depth = this->game.player2.depth;
        }
    }else {
        s = "White";
        p = this->game.player1.type;
        if(p != Human){
            depth = this->game.player1.depth;
        }
    }
    if(p == Human){
        s += "(Human)";
    }else if(p == MinMax){
        s += "(MinMax depth " + std::to_string(depth) + ")";
    }else if(p == MinMaxAB){
        s += "(MinMaxAB depth " + std::to_string(depth) + ")";
    }
    s += "\n   ";
    s += "(" + std::to_string(mov.getSX()) + "," + std::to_string(mov.getSY()) + ") to (" + std::to_string(mov.getDX()) + "," + std::to_string(mov.getDY()) + ") in " + std::to_string(time) + "ms\n";

    std::ofstream ofs;
    ofs.open("logs.txt", std::ofstream::out | std::ofstream::app);
    ofs << s;
    ofs.close();
}

void Interface::printEndGame(Team winner, int nturns, double averagew, double averageb){
    std::string s = "";
    if(winner == White){
        s += "White ";
    }else s += "Black ";
    s+= "won in " + std::to_string(nturns) + " turns\n";
    s+= "White time average : " + std::to_string(averagew) + "ms\n";
    s+= "White time average : " + std::to_string(averageb) + "ms\n";
    std::ofstream ofs;
    ofs.open("logs.txt", std::ofstream::out | std::ofstream::app);
    ofs << s;
    ofs.close();
}
