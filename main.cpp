#include <iostream>
#include <memory>
#include "MindEngine2D/Loop/Main/game.hpp"

int main() {
	std::unique_ptr<AnkrGame> ankr_game_ = std::make_unique<AnkrGame>();
	ankr_game_->init();
	while (ankr_game_->isOpen()) {
		ankr_game_->run();
	}
	return 0;
}