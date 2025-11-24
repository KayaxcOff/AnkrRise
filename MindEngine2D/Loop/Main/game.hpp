#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "../../Core/Physic/physic.hpp"

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
	sf::Event event;

	std::unique_ptr<AnkrPhysic> ankr_physic_;

	void processEvents();
	void update(float deltaTime);
	void render();
};