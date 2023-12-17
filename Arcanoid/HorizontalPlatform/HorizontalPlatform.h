#pragma once

#include "../Platform/Platform.h"

class HorizontalPlatform : public Platform {
public:
	HorizontalPlatform();

	void update(float dt);
};