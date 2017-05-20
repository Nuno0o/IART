#pragma once

#include "Game.h"

class Interface {
private:
	Game game;
	bool logs;
public:
	Interface();
	void Play();

	void clearLog();
	void printToLog(Team team,Move mov, double time);
	void printEndGame(Team winner, int nturns, double averagew, double averageb);
};
