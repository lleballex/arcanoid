#include "SolidBlock.h"

SolidBlock::SolidBlock(float x, float y, COLOR color) : Block(x, y, color) {}

bool SolidBlock::isAlive() {
	return true;
}

bool SolidBlock::isSolid() {
	return true;
}