#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <Box2D/box2d.h>
#include "../../Core/fppxh.hpp"

class Champion : public Entity2D {
protected:
	std::string _name;
	int _health;
	int _maxHealth;
	int _attackPower;
public:
	Champion(const std::string& name, int maxHealth, int attackPower, std::string& _file, b2Body* _body)
		: Entity2D(_file, _body), _name(name), _health(maxHealth), _maxHealth(maxHealth), _attackPower(attackPower) {}
	virtual ~Champion() = default;
	virtual void attack(Champion& target) {
		target.takeDamage(_attackPower);
	}
	virtual void takeDamage(int damage) {
		_health -= damage;
		if (_health < 0) _health = 0;
	}
	virtual bool isAlive() const {
		return _health > 0;
	}
	virtual std::string getName() const {
		return _name;
	}
	virtual int getHealth() const {
		return _health;
	}
	virtual int getMaxHealth() const {
		return _maxHealth;
	}
};