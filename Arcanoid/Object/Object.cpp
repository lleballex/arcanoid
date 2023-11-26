#include "Object.h"

Object::Object() {};

Object::Object(float x, float y) : x(x), y(y) {};

Object::Object(float x, float y, float width, float height): x(x), y(y), width(width), height(height) {}

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
