#pragma once

#include <SFML/Graphics.hpp>
#include "../EventManager/EventManager.h"

class BaseScene {
protected:
	EventManager& eventManager = EventManager::getInstance();

public:
	virtual ~BaseScene();

	virtual void update(float dt) {};
	virtual void draw(sf::RenderWindow *window) = 0;
};