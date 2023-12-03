#include "App.h"
#include "../Game/Game.h"
#include "../Home/Home.h"

App::App() {
	currentScene = new Home;
	
	srand(time(NULL));

	eventManager.subscribe(EVENT::GO_HOME, nullptr, this, std::bind(&App::setHomeScene, this));
	eventManager.subscribe(EVENT::GO_GAME, nullptr, this, std::bind(&App::setGameScene, this));
	eventManager.subscribe(EVENT::GO_RULES, nullptr, this, std::bind(&App::setRulesScene, this));
	eventManager.subscribe(EVENT::GO_ABOUT, nullptr, this, std::bind(&App::setAboutScene, this));
	eventManager.subscribe(EVENT::QUIT, nullptr, this, std::bind(&App::quit, this));
}	

App::~App() {
	delete currentScene;
}

void App::setHomeScene() {
	delete currentScene;
	currentScene = new Home;
}

void App::setGameScene() {
	delete currentScene;
	currentScene = new Game;
}

void App::setRulesScene() {
	//delete currentScene;
	//currentScene = new Rules;
}

void App::setAboutScene() {
	//delete currentScene;
	//currentScene = new About;
}

void App::quit() {
	isRunning = false;
}

void App::run() {
	isRunning = true;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ARCANOID by lleballex");

	window.setFramerateLimit(60);

	sf::Clock clock;

	while (isRunning) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else {
				eventManager.emitSFML(&event, &window);
			}
		}

		const float dt = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		if (currentScene) {
			currentScene->update(dt);
		}

		window.clear(sf::Color(COLOR::BLACK));
		
		if (currentScene) {
			currentScene->draw(&window);
		}

		window.display();
	}
}