#pragma once

#include "../Circle/Circle.h"
#include "../config.h"

class Ball : public Circle {
private:
	COLOR color;
	float speed = 0.4;

public:
	Ball();

	void update(float dt);
	void draw(sf::RenderWindow *window);
	bool handlePlatformCollide(float plX, float plY, float plWidth, float plHeight);
	bool handleBlockCollide(float blockX, float blockY, float blockWidth, float blockHeight);

	void setColor(COLOR newColor);
	void setSpeedAngle(float angle);

	COLOR getColor();
};