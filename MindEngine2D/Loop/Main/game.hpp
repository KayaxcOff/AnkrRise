#pragma once

#include <SFML/Graphics.hpp>

class AnkrGame {
public:
	AnkrGame(int offsetX=800, int offsetY=600);
	~AnkrGame();

	void init();
	void run();
	[[nodiscard]] bool isOpen() const;
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
};