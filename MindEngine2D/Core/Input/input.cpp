#include "input.hpp"

AnkrInput::AnkrInput() = default;

AnkrInput::~AnkrInput() = default;

bool AnkrInput::isPressed(sf::Keyboard::Key key) const {
	return sf::Keyboard::isKeyPressed(key);
}