#include "Platform.h"
#include "../colors.h"

Platform::Platform() : Rect(0, 0) {};

void Platform::draw(sf::RenderWindow *window) {
	shape->setFillColor(sf::Color(COLOR::WHITE));
	window->draw(*shape);
}

void Platform::moveLeft(float dt, float minX) {
	if (speedX) {
		x -= speedX * dt;
		if (x < minX) {
			x = minX;
		}
		onPositionChange();
	}
}

void Platform::moveRight(float dt, float maxX) {
	if (speedX) {
		x += speedX * dt;
		if (x + width > maxX) {
			x = maxX - width;
		}
	}
	onPositionChange();
}

void Platform::moveUp(float dt, float minY) {
	if (speedY) {
		y -= speedY * dt;
		if (y < minY) {
			y = minY;
		}
	}
	onPositionChange();
}

void Platform::moveDown(float dt, float maxY) {
	if (speedY) {
		y += speedY * dt;
		if (y + height > maxY) {
			y = maxY - height;
		}
	}
	onPositionChange();
}