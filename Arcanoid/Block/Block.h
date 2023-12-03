#pragma once

#include "../Rect/Rect.h"
#include "../Ball/Ball.h"
#include "../config.h"

class Block : public Rect {
protected:
	int health = 1;

	COLOR color;

public:
	Block(float x, float y, COLOR color);

	void draw(sf::RenderWindow *window);
	virtual void onBallCollide(Ball *ball);

	virtual bool isAlive();
	virtual bool isSolid();

	COLOR getColor();
};