#include "Game.h"

PlayerSettings::PlayerSettings() {
	this->type = Human;
	this->depth = 1;
}

PlayerSettings::PlayerSettings(PlayerType type) {
	this->type = type;
	this->depth = 1;
}

PlayerSettings::PlayerSettings(PlayerType type,int depth) {
	this->type = type;
	this->depth = depth;
}

Game::Game() {
	this->player1 = PlayerSettings();
	this->player2 = PlayerSettings();
}
Game::Game(PlayerSettings player1, PlayerSettings player2) {
	this->player1 = player1;
	this->player2 = player2;
}