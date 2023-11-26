#include "ColorTransition.h"

ColorTransition::ColorTransition(sf::Color currentColor) : ColorTransition(currentColor, 200) {}

ColorTransition::ColorTransition(sf::Color currentColor, float duration) : current(currentColor), duration(duration) {}

void ColorTransition::start( sf::Color to_) {
	isActive = true;
	elapsedTime = 0;
	from = current;
	to = to_;
}

void ColorTransition::update(float dt) {
	if (isActive) {
		elapsedTime += dt;
		float d = std::min(1.f, elapsedTime / duration);

		current = sf::Color(
			from.r * (1 - d) + to.r * d,
			from.g * (1 - d) + to.g * d,
			from.b * (1 - d) + to.b * d
		);

		if (elapsedTime >= duration) {
			isActive = false;
		}
	}
}

sf::Color ColorTransition::getColor() {
	return current;
}