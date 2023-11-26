#pragma once

#include "../Block/Block.h"

class SolidBlock : public Block {
public:
	SolidBlock(float x, float y, COLOR color);

	bool isAlive();
	bool isSolid();
};