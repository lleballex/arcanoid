#pragma once

#include "../Object/Object.h"
#include "../config.h"

class Circle : public Object {
protected:
	float radius;

	sf::CircleShape* shape;

	void setRadius(float radius);

private:
	void onResize();
	void onMove();

public:
	Circle(float radius);
	Circle(float x, float y, float radius);
	virtual ~Circle();

	float* getRectCollision(float rectX, float rectY, float rectWidth, float rectHeight);
	float getRadius();
};