#pragma once

#include "../BaseScene/BaseScene.h"
#include "../Button/Button.h"
#include "../VerticalLayout/VerticalLyout.h"

class Home : public BaseScene {
private:
	VerticalLayout* layout = nullptr;
	Button* startBtn = nullptr;
	Button* rulesBtn = nullptr;
	Button* aboutBtn = nullptr;
	Button* quitBtn = nullptr;

	void setGameScene();
	void setRulesScene();
	void setAboutScene();
	void quit();

public:
	Home();
	~Home();

	void update(float dt);
	void draw(sf::RenderWindow* window);
};