#pragma once

#include "../BaseScene/BaseScene.h"
#include "../Button/Button.h"
#include "../VerticalLayout/VerticalLyout.h"
#include "../config.h"

class Home : public BaseScene {
private:
	VerticalLayout* layout = nullptr;
	Button* startBtn = nullptr;
	Button* rulesBtn = nullptr;
	Button* aboutBtn = nullptr;
	Button* quitBtn = nullptr;

	void setNextScene(SCENE scene);

public:
	Home();
	~Home();

	void handleEvent(sf::Event *event, sf::RenderWindow *window);
	void update(float dt);
	void draw(sf::RenderWindow* window);
};