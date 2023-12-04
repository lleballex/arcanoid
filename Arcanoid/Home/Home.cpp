#include "Home.h"

Home::Home() {
	const int btnWidth = 200;
	const int btnHeight = 70;

	startBtn = new Button(btnWidth, btnHeight, "Start");
	rulesBtn = new Button(btnWidth, btnHeight, "Rules");
	aboutBtn = new Button(btnWidth, btnHeight, "About");
	quitBtn = new Button(btnWidth, btnHeight, "Quit");

	eventManager.subscribe(EVENT::CLICK, startBtn, &Home::setGameScene, this);
	eventManager.subscribe(EVENT::CLICK, rulesBtn, &Home::setRulesScene, this);
	eventManager.subscribe(EVENT::CLICK, aboutBtn, &Home::setAboutScene, this);
	eventManager.subscribe(EVENT::CLICK, quitBtn, &Home::quit, this);


	layout = new VerticalLayout(5, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	layout->addObject(startBtn);
	layout->addObject(rulesBtn);
	layout->addObject(aboutBtn);
	layout->addObject(quitBtn);
}

Home::~Home(){
	delete startBtn;
	delete rulesBtn;
	delete aboutBtn;
	delete quitBtn;
	delete layout;
}

void Home::setGameScene() {
	eventManager.emit(EVENT::GO_GAME, this);
}

void Home::setRulesScene() {
	eventManager.emit(EVENT::GO_RULES, this);
}

void Home::setAboutScene() {
	eventManager.emit(EVENT::GO_ABOUT, this);
}

void Home::quit() {
	eventManager.emit(EVENT::QUIT, this);
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