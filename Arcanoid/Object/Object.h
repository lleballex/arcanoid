#pragma once

#include <SFML/Graphics.hpp>

class Object {
protected:
	float x = 0, y = 0;
	float width = 0, height = 0;
	float speedX = 0, speedY = 0;

public:
	Object();
	Object(float x, float y);
	Object(float x, float y, float width, float height);

	virtual void draw(sf::RenderWindow *window) = 0;

	virtual void onSizeChange() {};
	virtual void onPositionChange() {};

	virtual bool contains(float x, float y);
	virtual bool contains(float x, float y, float width, float height);
	virtual bool containsWeakly(float x, float y, float width, float height);

	virtual bool isInside(float x, float y, float width, float height);
	virtual bool isInsideWeakly(float x, float y, float width, float height);

	void setPosition(float x, float y);
	void setX(float x);
	void setY(float y);

	float getX();
	float getY();
	float getWidth();
	float getHeight();
};