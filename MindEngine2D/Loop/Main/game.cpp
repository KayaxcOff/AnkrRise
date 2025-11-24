#include "game.hpp"

AnkrGame::AnkrGame(int offsetX, int offsetY) : SCREEN_WIDTH(offsetX), SCREEN_HEIGHT(offsetY) {
	this->window = nullptr;
	this->videoMode = sf::VideoMode(this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
	this->event = sf::Event();
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

void AnkrGame::run() {
	this->update(1.0f / 60.0f);
	this->render();
}

bool AnkrGame::isOpen() const {
	return this->window->isOpen();
}

void AnkrGame::processEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void AnkrGame::update(float deltaTime) {
	this->processEvents();
	this->ankr_physic_->update(deltaTime);
}

void AnkrGame::render() {
	this->window->clear(sf::Color::Black);
	// Draw your game objects here
	this->window->display();
}