#include "Block.h"
#include "../Game/utils.h"

Block::Block(float x, float y, COLOR color) : Rect(x, y, 75, 45), color(color) {
	shape->setFillColor(sf::Color(color));

	eventManager.subscribe(EVENT::GAME_COLLIDE_BALL_BLOCK, nullptr, &Block::onBallCollide, this);
};

void Block::onBallCollide(void *data_) {
	BallBlockCollideData* data = static_cast<BallBlockCollideData*>(data_);
	if (data->block == this && !isSolid() && isAlive() && (isMulti() || data->ball->getColor() == color)) {
		health -= 1;
	}
}

void Block::draw(sf::RenderWindow *window) {
	if (isAlive()) {
		window->draw(*shape);
	}
}

bool Block::isAlive() {
	return health > 0;
}

bool Block::isSolid() {
	return false;
}

bool Block::isMulti() {
	return false;
}

COLOR Block::getColor() {
	return color;
}