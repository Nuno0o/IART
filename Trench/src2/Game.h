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
    //Game board
	Board board;
	//Settings of player1
	PlayerSettings player1;
	//Settings of player2
	PlayerSettings player2;
    //Default constructor with both players human
	Game();
	//Constructor with player configurations
	Game(PlayerSettings player1,PlayerSettings player2);

};
