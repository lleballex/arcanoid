#pragma once

#include "../Rect/Rect.h"

class Platform : public Rect {
protected:
	float length = 160, breadth = 20, speed = 1.1;
	
public:
	Platform();

	void draw(sf::RenderWindow *window);
	void moveLeft(float dt, float minX);
	void moveRight(float dt, float maxX);
	void moveUp(float dt, float minY);
	void moveDown(float dt, float maxY);
};