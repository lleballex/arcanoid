#include "Circle.h"

Circle::Circle(float radius) : Circle(0, 0, radius) {};

Circle::Circle(float x, float y, float radius) : Object(x, y, radius * 2, radius * 2), radius(radius) {
	shape = new sf::CircleShape();
	onSizeChange();
	onPositionChange();
};

Circle::~Circle() {
	delete shape;
}

void Circle::onSizeChange() {
	shape->setRadius(radius);
	Object::onSizeChange();
}

void Circle::onPositionChange() {
	shape->setPosition(x, y);
	Object::onPositionChange();
}

float* Circle::getRectCollision(float rectX, float rectY, float rectWidth, float rectHeight) {
	int closestX = std::max(std::min(x + radius, rectX + rectWidth), rectX);
	int closestY = std::max(std::min(y + radius, rectY + rectHeight), rectY);

	int distanceX = x + radius - closestX;
	int distanceY = y + radius - closestY;

	if (distanceX * distanceX + distanceY * distanceY > radius * radius) {
		return nullptr;
	}

	float* res = new float[2];
	res[0] = distanceX;
	res[1] = distanceY;

	return res;
}

void Circle::setRadius(float radius_) {
	radius = radius_;
	onSizeChange();
}


float Circle::getRadius() {
	return radius;
}