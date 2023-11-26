#include "App.h"
#include "../Game/Game.h"
#include "../Home/Home.h"

#include <iostream>

App::App() {
	currentScene = new Home;
	
	srand(time(NULL));
}	

App::~App() {
	delete currentScene;
}

void App::run() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ARCANOID by lleballex");

	window.setFramerateLimit(60);

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else {
				currentScene->handleEvent(&event, &window);
			}
		}

		const float dt = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		currentScene->update(dt);

		window.clear(sf::Color(COLOR::BACKGROUND));
		currentScene->draw(&window);
		window.display();

		switch (currentScene->getNextScene()) {
		case SCENE::NONE:
			break;
		case SCENE::QUIT:
			window.close();
			break;
		case SCENE::HOME:
			delete currentScene;
			currentScene = new Home;
			break;
		case SCENE::GAME:
			delete currentScene;
			currentScene = new Game;
			break;
		case SCENE::RULES:
			break;
		case SCENE::ABOUT:
			break;
		}
	}
}