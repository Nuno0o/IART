#pragma once

#include "Game.h"

class Interface {
public:
    //Build interface
	Interface();
private:
    //Game
	Game game;
	//Indicates if logs shall be output to logs.txt
	bool logs;
	//Indicates if a key should be pressed to see what the bot does
	bool stop;
	//Play(automatically called by constructor)
	void Play();
	//Clear log file and create if doesnt exist
	void clearLog();
	//Print a turn to log file
	void printToLog(Team team,Move mov, double time);
	//Print end game stats to log
	void printEndGame(Team winner, int nturns, double averagew, double averageb);
};
