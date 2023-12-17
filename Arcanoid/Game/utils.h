#pragma once

#include "../Ball/Ball.h"
#include "../Block/Block.h"
#include "../Platform/Platform.h"

struct BallBlockCollideData {
	Ball* ball;
	Block* block;
	float* collision;
};

struct BallPlatformCollideData {
	Ball* ball;
	Platform* platform;
	float* collision;
};