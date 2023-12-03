#include "Object.h"

Object::Object() : Object(0, 0) {};

Object::Object(float x, float y) : Object(x, y, 0, 0) {};

Object::Object(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {
	eventManager.subscribeSFML(this, std::bind(&Object::baseHandleSFMLEvent, this, std::placeholders::_1, std::placeholders::_2));
}

Object::~Object() {
	eventManager.unsubscribe(this);
}

void Object::baseHandleSFMLEvent(sf::Event* event, sf::RenderWindow* window) {
	if (event->type == sf::Event::MouseButtonReleased) {
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		if (pos.x >= x && pos.x <= x + width && pos.y >= y && pos.y <= y + height) {
			eventManager.emit(EVENT::CLICK, this);
		}
	}
	else if (event->type == sf::Event::MouseMoved) {
		sf::Vector2i pos = sf::Mouse::getPosition(*window);
		if (!isHovered && contains(pos.x, pos.y)) {
			isHovered = true;
			eventManager.emit(EVENT::HOVER, this);
		} else if (isHovered && !contains(pos.x, pos.y)) {
			isHovered = false;
			eventManager.emit(EVENT::UNHOVER, this);
		}
	}
}

void Object::onPositionChange() {
	eventManager.emit(EVENT::MOVE, this);
}

void Object::onSizeChange() {
	eventManager.emit(EVENT::RESIZE, this);
}

bool Object::contains(float x_, float y_) {
	return x_ >= x && x_ <= x + width && y_ >= y && y_ <= y + height;
}

bool Object::contains(float x_, float y_, float width_, float height_) {
	return x_ >= x && x_ + width_ <= x + width && y_ >= y && y_ + height_ <= y + height;
}

bool Object::containsWeakly(float x_, float y_, float width_, float height_) {
	return x_ <= x + width && x_ + width_ >= x && y_ <= y + height && y_ + height_ >= y;
}

bool Object::isInside(float x_, float y_, float width_, float height_) {
	return x >= x_ && x + width <= x_ + width_ && y >= y_ && y + height <= y_ + height_;
}

bool Object::isInsideWeakly(float x_, float y_, float width_, float height_) {
	return x <= x_ + width_ && x + width >= x_ && y <= y_ + height_ && y + height >= y_;
}

void Object::setPosition(float x_, float y_) {
	x = x_;
	y = y_;
	onPositionChange();
}

void Object::setX(float x_) {
	x = x_;
	onPositionChange();
}

void Object::setY(float y_) {
	y = y_;
	onPositionChange();
}

float Object::getX() {
	return x;
}

float Object::getY() {
	return y;
}

float Object::getWidth() {
	return width;
}

float Object::getHeight() {
	return height;
}
