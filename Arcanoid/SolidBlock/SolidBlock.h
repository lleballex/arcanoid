#pragma once

#include "../Block/Block.h"

class SolidBlock : public Block {
private:
	sf::RectangleShape* innerShape;

public:
	SolidBlock(float x, float y, COLOR color);
	~SolidBlock();

	void draw(sf::RenderWindow* window);
	void onSizeChange();
	void onPositionChange();

	bool isAlive();
	bool isSolid();
};