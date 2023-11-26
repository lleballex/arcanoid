#pragma once

#include <SFML/Graphics.hpp>
#include "../config.h"

class BaseScene {
protected:
	SCENE nextScene = SCENE::NONE;

public:
	virtual void handleEvent(sf::Event* event, sf::RenderWindow *window) {};
	virtual void update(float dt) {};
	virtual void draw(sf::RenderWindow *window) = 0;

	SCENE getNextScene();
};