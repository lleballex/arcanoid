#pragma once

#include "../Circle/Circle.h"
#include "../config.h"
//#include "../Game/utils.h"

class Ball : public Circle {
private:
	COLOR color;

	float speed = 0.4;
	float centerX = 10, centerY = 10;
	
	void onBlockCollide(void *data);
	void onPlatformCollide(void* data);

	void setColor(COLOR newColor);

public:
	Ball();

	void update(float dt);
	void draw(sf::RenderWindow *window);

	void setSpeedAngle(float angle);
	void setCenterPosition(float x, float y);

	COLOR getColor();
};