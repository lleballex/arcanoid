#pragma once

#include "../config.h"

#include <SFML/Graphics.hpp>
#include <functional>

struct EventHandler {
	EVENT event;
	void* sender;
	void* reciever;
	std::function<void()> callback;
};

struct SFMLEventHandler {
	void* reciever;
	std::function<void(sf::Event*, sf::RenderWindow*)> callback;
};

class EventManager {
private:
	EventHandler* handlers;
	SFMLEventHandler* sfmlHandlers;

	int handlersCount = 0, sfmlHandlersCount = 0;

	EventManager();
	~EventManager();

public:
	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;

	static EventManager& getInstance();

	void emit(EVENT event, void *source);
	void emitSFML(sf::Event *event, sf::RenderWindow *window);
	void subscribe(EVENT event, void *sender, void *reciever, std::function<void()> callback);
	void subscribeSFML(void *reciever, std::function<void(sf::Event*, sf::RenderWindow*)> callback);
	void unsubscribe(void *reciever);
};