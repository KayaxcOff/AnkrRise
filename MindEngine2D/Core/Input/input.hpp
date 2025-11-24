#pragma once

#include <SFML/Graphics.hpp>

class AnkrInput {
public:
	AnkrInput();
	~AnkrInput();

	[[nodiscard]] bool isPressed(sf::Keyboard::Key key) const;
};