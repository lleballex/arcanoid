#include "Rect.h"

Rect::Rect(float width, float height) : Rect(0, 0, width, height) {};

Rect::Rect(float x, float y, float width, float height) : Object(x, y, width, height) {
	shape = new sf::RectangleShape();
	onPositionChange();
	onSizeChange();
};

Rect::~Rect() {
	delete shape;
}

void Rect::onSizeChange() {
	shape->setSize(sf::Vector2f(width, height));
	Object::onSizeChange();
}

void Rect::onPositionChange() {
	shape->setPosition(x, y);
	Object::onPositionChange();
}

void Rect::setSize(float width_, float height_) {
	width = width_;
	height = height_;
	onSizeChange();
}

void Rect::setWidth(float width_) {
	width = width_;
	onSizeChange();
}

void Rect::setHeight(float height_) {
	height = height_;
	onSizeChange();
}