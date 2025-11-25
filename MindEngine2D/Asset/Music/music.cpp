#include "music.hpp"

AnkrMusic::AnkrMusic(std::string& _path) : path(_path) {}

AnkrMusic::~AnkrMusic() {
	this->music.stop();
}

void AnkrMusic::init() {
	if (!this->music.openFromFile(this->path)) {
		std::cerr << "Error: Could not load music from path: " << this->path << std::endl;
	}
}

void AnkrMusic::play() {
	this->music.play();
}

void AnkrMusic::pause() {
	this->music.pause();
}

void AnkrMusic::stop() {
	this->music.stop();
}