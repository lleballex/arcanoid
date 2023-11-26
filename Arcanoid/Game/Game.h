#pragma once

#include "../BaseScene/BaseScene.h"
#include "../Block/Block.h"
#include "../Platform/Platform.h"
#include "../Ball/Ball.h"
#include "../config.h"

class Game : public BaseScene {
private:
	int blocksCount = 0;
	int platformsCount = 0;

	Block** blocks;
	Platform** platforms;
	Ball* ball;

public:
	Game();
	~Game();

	void update(float dt);
	void draw(sf::RenderWindow *window);
};