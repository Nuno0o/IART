#pragma once

#include "Board.h"

struct PlayerSettings {
public:
	PlayerType type;
	int depth;
	
	PlayerSettings();
	PlayerSettings(PlayerType type);
	PlayerSettings(PlayerType type, int depth);
};

class Game {
public:
	Board board;
	PlayerSettings player1;
	PlayerSettings player2;

	Game();
	Game(PlayerSettings player1,PlayerSettings player2);

};