#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

class AnkrMusic {
public:
	AnkrMusic(std::string& _path);
	~AnkrMusic();

	void init();
	void play();
	void pause();
	void stop();
private:
	sf::Music music;
	std::string path;
};