#pragma once 

#include "../Platform/Platform.h"

class VerticalPlatform : public Platform {
public:
	VerticalPlatform();

	void update(float dt);
};