#pragma once

#include "../BaseScene/BaseScene.h"
#include "../Block/Block.h"
#include "../Platform/Platform.h"
#include "../Ball/Ball.h"
#include "../config.h"

class Game : public BaseScene {
private:
	// if ball is moving
	bool isStarted = false;

	int activePlatformIdx = 1;

	int health = 5;
	int blocksCount = 0;

	Block** blocks;
	Platform** platforms;
	Ball* ball;

	sf::Texture *heartTexture;
	sf::Sprite *heart;

	void setInitBallPosition();
	void setActivePlatformIdx(int idx);
	void handleSFMLEvent(sf::Event *event, sf::RenderWindow *window);

public:
	Game();
	~Game();

	void update(float dt);
	void draw(sf::RenderWindow *window);
};