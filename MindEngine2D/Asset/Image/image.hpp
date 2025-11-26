#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class AnkrImage {
public:
	AnkrImage();
	~AnkrImage();

	void initializeTexture(std::string& _path);
	sf::Sprite& getSprite();
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string path;
};