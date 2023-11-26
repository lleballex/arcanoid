#pragma once

#include "../BaseScene/BaseScene.h"

#include <SFML/Graphics.hpp>

class App {
private:
	BaseScene* currentScene;

public:
	App();
	~App();

	void run();
};