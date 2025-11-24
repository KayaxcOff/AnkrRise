#include "game.hpp"

AnkrGame::AnkrGame(int offsetX, int offsetY) : SCREEN_WIDTH(offsetX), SCREEN_HEIGHT(offsetY) {
	this->window = nullptr;
	this->videoMode = sf::VideoMode(this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
}

AnkrGame::~AnkrGame() {
	if (this->window != nullptr) {
		delete this->window;
	}
}

void AnkrGame::init() {
	this->window = new sf::RenderWindow(this->videoMode, "Ankr : Rise", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);

	this->ankr_physic_ = std::make_unique<AnkrPhysic>();
	this->ankr_physic_->init(100.0f);
}

void AnkrGame::run() {}

bool AnkrGame::isOpen() const {
	return this->window->isOpen();
}