#pragma once

#include "../Rect/Rect.h"
#include "../config.h"

class Block : public Rect {
private:
	void onBallCollide(void *data);

protected:
	int health = 1;

	COLOR color = COLOR::WHITE;

public:
	Block(float x, float y, COLOR color);

	void draw(sf::RenderWindow *window);

	virtual bool isAlive();
	virtual bool isSolid();
	virtual bool isMulti();

	COLOR getColor();
};