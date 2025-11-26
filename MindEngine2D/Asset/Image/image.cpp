#include "image.hpp"

AnkrImage::AnkrImage() : texture(), sprite(), path() {}

AnkrImage::~AnkrImage() {}

void AnkrImage::initializeTexture(std::string& _path) {
	this->path = _path;
	if (!this->texture.loadFromFile(this->path)) {
		std::cerr << "Error: Could not load texture from file: " << this->path << std::endl;
	}
	this->sprite.setTexture(this->texture);
}

sf::Sprite& AnkrImage::getSprite() {
	return this->sprite;
}