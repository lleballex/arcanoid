#pragma once

#include "../Rect/Rect.h"

class VerticalLayout : public Object {
private:
	int objectsCount;
	int lastObjectIdx = -1;
	float gap = 50;
	float contentHeight = 0;

	Object** objects;

public:
	VerticalLayout(int objectsCount, float width, float height);
	VerticalLayout(int objectsCount, float x, float y, float width, float height);
	~VerticalLayout();

	void addObject(Object *obj);
	void update(float dt);
	void draw(sf::RenderWindow* window);

	void setGap(float gap);
};