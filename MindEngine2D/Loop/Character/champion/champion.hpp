#pragma once

#include "../character.hpp"

class Characters : public Champion {
public:
	Characters(const std::string& name, int health, int attackPower, std::string& file, b2Body* body)
		: Champion(name, health, attackPower, file, body) {
		this->body = body;
		this->hp = health;
		this->ap = attackPower;
		this->name = name;
	}
	~Characters() {}

	void move(float x, float y) {
		body->SetTransform(b2Vec2(x, y), body->GetAngle());
	}

private:
	b2Body* body;
	int hp;
	int ap;
	std::string name;
};

