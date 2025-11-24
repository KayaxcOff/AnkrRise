#include "game.hpp"

AnkrGame::AnkrGame(int offsetX, int offsetY) : SCREEN_WIDTH(offsetX), SCREEN_HEIGHT(offsetY) {
	this->window = nullptr;
	this->videoMode = sf::VideoMode(this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
}