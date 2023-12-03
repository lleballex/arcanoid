#include "SolidBlock.h"

SolidBlock::SolidBlock(float x, float y, COLOR color) : Block(x, y, color) {
	innerShape = new sf::RectangleShape();
	innerShape->setFillColor(sf::Color(COLOR::WHITE));

	onPositionChange();
	onSizeChange();
}

SolidBlock::~SolidBlock() {
	delete innerShape;
}

void SolidBlock::draw(sf::RenderWindow* window) {
	window->draw(*shape);
	window->draw(*innerShape);
}

void SolidBlock::onPositionChange() {
	shape->setPosition(x, y);
	innerShape->setPosition(x + 5, y + 5);
}

void SolidBlock::onSizeChange() {
	shape->setSize(sf::Vector2f(width, height));
	innerShape->setSize(sf::Vector2f(width - 10, height - 10));
}

bool SolidBlock::isAlive() {
	return true;
}

bool SolidBlock::isSolid() {
	return true;
}