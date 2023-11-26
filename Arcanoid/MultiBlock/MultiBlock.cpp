#include "MultiBlock.h"

MultiBlock::MultiBlock(float x, float y) : Block(x, y, COLOR::WHITE) {};

void MultiBlock::onBallCollide(COLOR ballColor) {
	health -= 1;
}