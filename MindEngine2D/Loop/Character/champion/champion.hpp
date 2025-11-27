#pragma once

#include "../character.hpp"

class Characters : public Champion {
public:
	Characters(const std::string& _name, int _hp, int _maxHp, int _attack, std::string& _file, b2Body* _body) 
		: Champion(_name, _hp, _maxHp, _attack, _file, _body) {}
	~Characters() {}

private:

};

