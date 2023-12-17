#include "Platform.h"
#include "../config.h"

Platform::Platform() : Rect(0, 0) {};

void Platform::draw(sf::RenderWindow *window) {
	shape->setFillColor(sf::Color(COLOR::WHITE));
	window->draw(*shape);
}

void Platform::setBorders(float min, float max) {
	minBorder = min;
	maxBorder = max;
}