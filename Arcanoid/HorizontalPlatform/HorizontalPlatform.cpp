#include "HorizontalPlatform.h"

HorizontalPlatform::HorizontalPlatform() : Platform() {
	setSize(length, breadth);
}

void HorizontalPlatform::update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x += dt * speed;
		if (x + width > maxBorder) {
			x = maxBorder - width;
		}
		setX(x);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= dt * speed;
		if (x < minBorder) {
			x = minBorder;
		}
		setX(x);
	}
}