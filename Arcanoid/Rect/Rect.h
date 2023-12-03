#pragma once

#include "../Object/Object.h"

class Rect : public Object {
protected:
	sf::RectangleShape* shape = nullptr;

	void setSize(float width, float height);
	void setWidth(float width);
	void setHeight(float height);

private:
	void onResize();
	void onMove();

public:
	Rect(float width, float height);
	Rect(float x, float y, float width, float height);
	virtual ~Rect();	
};