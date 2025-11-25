#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "../../Core/Physic/physic.hpp"
#include "../../Core/Input/input.hpp"
#include "../../Asset/Music/music.hpp"

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
	std::unique_ptr<AnkrInput> ankr_input_;
	std::unique_ptr<AnkrMusic> ankr_music_;

	void processEvents();
	void update(float deltaTime);
	void render();
};