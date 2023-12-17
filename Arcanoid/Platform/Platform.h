#pragma once

#include "../Rect/Rect.h"

class Platform : public Rect {
protected:
	float length = 160, breadth = 20, speed = 1.1;
	float minBorder = 0, maxBorder = 0;
	
public:
	Platform();

	virtual void update(float dt) {};
	void draw(sf::RenderWindow *window);

	void setBorders(float min, float max);
};