#include "Rect.h"

Rect::Rect(float width, float height) : Rect(0, 0, width, height) {};

Rect::Rect(float x, float y, float width, float height) : Object(x, y, width, height) {
	shape = new sf::RectangleShape();
	onMove();
	onResize();

	eventManager.subscribe(EVENT::MOVE, this, &Rect::onMove, this);
	eventManager.subscribe(EVENT::RESIZE, this, &Rect::onResize, this);
};

Rect::~Rect() {
	delete shape;
}

void Rect::onResize() {
	shape->setSize(sf::Vector2f(width, height));
}

void Rect::onMove() {
	shape->setPosition(x, y);
}

void Rect::setSize(float width_, float height_) {
	width = width_;
	height = height_;
	eventManager.emit(EVENT::RESIZE, this);
}

void Rect::setWidth(float width_) {
	width = width_;
	eventManager.emit(EVENT::RESIZE, this);
}

void Rect::setHeight(float height_) {
	height = height_;
	eventManager.emit(EVENT::RESIZE, this);
}