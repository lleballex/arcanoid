#pragma once

#include "../Block/Block.h"

class MultiBlock : public Block {
public:
	MultiBlock(float x, float y);

	bool isMulti();
};