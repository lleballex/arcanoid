#include "Home.h"

Home::Home() {
	const int btnWidth = 200;
	const int btnHeight = 70;

	startBtn = new Button(btnWidth, btnHeight, "Start");
	rulesBtn = new Button(btnWidth, btnHeight, "Rules");
	aboutBtn = new Button(btnWidth, btnHeight, "About");
	quitBtn = new Button(btnWidth, btnHeight, "Quit");

	startBtn->setOnClick(std::bind(&Home::setNextScene, this, SCENE::GAME));
	rulesBtn->setOnClick(std::bind(&Home::setNextScene, this, SCENE::RULES));
	aboutBtn->setOnClick(std::bind(&Home::setNextScene, this, SCENE::ABOUT));
	quitBtn->setOnClick(std::bind(&Home::setNextScene, this, SCENE::QUIT));

	layout = new VerticalLayout(5, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	layout->addObject(startBtn);
	layout->addObject(rulesBtn);
	layout->addObject(aboutBtn);
	layout->addObject(quitBtn);
}

Home::~Home() {
	delete startBtn;
	delete rulesBtn;
	delete aboutBtn;
	delete quitBtn;
	delete layout;
}

void Home::setNextScene(SCENE scene) {
	nextScene = scene;
}

void Home::handleEvent(sf::Event* event, sf::RenderWindow* window) {
	startBtn->handleEvent(event, window);
	rulesBtn->handleEvent(event, window);
	aboutBtn->handleEvent(event, window);
	quitBtn->handleEvent(event, window);
}

void Home::update(float dt) {
	startBtn->update(dt);
	rulesBtn->update(dt);
	aboutBtn->update(dt);
	quitBtn->update(dt);
}

void Home::draw(sf::RenderWindow* window) {
	layout->draw(window);
}