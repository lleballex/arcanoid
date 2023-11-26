#pragma once

#include <SFML/Graphics.hpp>

class ColorTransition {
private:
	float duration;
	float elapsedTime = 0;
	bool isActive = false;

	sf::Color from;
	sf::Color to;
	sf::Color current;

public:
	ColorTransition(sf::Color currentColor);
	ColorTransition(sf::Color currentColor, float duration);

	void start(sf::Color to);
	void update(float dt);

	sf::Color getColor();
};