#include "Block.h"

Block::Block(float x, float y, COLOR color) : Rect(x, y, 75, 45), color(color) {
	shape->setFillColor(sf::Color(color));
};

void Block::draw(sf::RenderWindow *window) {
	if (isAlive()) {
		window->draw(*shape);
	}
}

void Block::onBallCollide(COLOR ballColor) {
	if (ballColor == color) {
		health -= 1;
	}
}

bool Block::isAlive() {
	return health > 0;
}

bool Block::isSolid() {
	return false;
}

COLOR Block::getColor() {
	return color;
}