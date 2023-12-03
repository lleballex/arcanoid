#pragma once

#include "../BaseScene/BaseScene.h"

#include <SFML/Graphics.hpp>

class App {
private:
	bool isRunning = false;

	BaseScene* currentScene;
	EventManager& eventManager = EventManager::getInstance();

	void setHomeScene();
	void setGameScene();
	void setRulesScene();
	void setAboutScene();
	void quit();

public:
	App();
	~App();

	void run();
};