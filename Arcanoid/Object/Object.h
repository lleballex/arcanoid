#pragma once

#include "../EventManager/EventManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Object {
protected:
	float x = 0, y = 0;
	float width = 0, height = 0;
	float speedX = 0, speedY = 0;

	bool isHovered = false;

	EventManager& eventManager = EventManager::getInstance();

public:
	Object();
	Object(float x, float y);
	Object(float x, float y, float width, float height);
	virtual ~Object();

	void baseHandleSFMLEvent(sf::Event* event, sf::RenderWindow* window);

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