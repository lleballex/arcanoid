#include "MultiBlock.h"

MultiBlock::MultiBlock(float x, float y) : Block(x, y, COLOR::GREEN) {};

bool MultiBlock::isMulti() {
	return true;
}