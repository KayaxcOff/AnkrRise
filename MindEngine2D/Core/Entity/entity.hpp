#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/box2d.h>

class Entity2D {
protected:
	sf::Sprite sprite;
	sf::Texture	texture;
	b2Body* body;
public:
	Entity2D(const std::string& texture_file, b2Body* body) {
		if (!texture.loadFromFile(texture_file)) {
			throw std::runtime_error("Failed to load texture: " + texture_file);
		}
		this->sprite.setTexture(texture);
		this->body = body;
	}
	virtual ~Entity2D() {
		if (body && body->GetWorld()) {
			body->GetWorld()->DestroyBody(body);
		}
	}
	void setPosition(float x, float y) {
		sprite.setPosition(x, y);
		body->SetTransform(b2Vec2(x, y), body->GetAngle());
	}
	void setRotation(float angle) {
		sprite.setRotation(angle);
		body->SetTransform(body->GetPosition(), angle * b2_pi / 180.0f);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	b2Body* getBody() {
		return body;
	}
};