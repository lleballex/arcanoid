#include "VerticalPlatform.h"

VerticalPlatform::VerticalPlatform() : Platform() {
	speedY = speed;
	setSize(breadth, length);
}

void VerticalPlatform::update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y += dt * speed;
		if (y + height > maxBorder) {
			y = maxBorder - height;
		}
		setY(y);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y -= dt * speed;
		if (y < minBorder) {
			y = minBorder;
		}
		setY(y);
	}
}