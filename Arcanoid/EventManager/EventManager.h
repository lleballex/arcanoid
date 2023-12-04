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
	void unsubscribe(void* reciever);

	template <class T>
	void subscribe(EVENT event, void* sender, void (T::* callback)(), T* reciever);

	template <class T>
	void subscribeSFML(void (T::*callback)(sf::Event*, sf::RenderWindow*), T *reciever);
};

template <class T>
void EventManager::subscribe(EVENT event, void *sender, void (T::*callback)(), T *reciever) {
	EventHandler handler;
	handler.event = event;
	handler.sender = sender;
	handler.reciever = reciever;
	handler.callback = std::bind(callback, reciever);
	handlers[handlersCount++] = handler;
}	

template <class T>
void EventManager::subscribeSFML(void (T::*callback)(sf::Event*, sf::RenderWindow*), T* reciever) {
	SFMLEventHandler handler;
	handler.reciever = reciever;
	handler.callback = std::bind(callback, reciever, std::placeholders::_1, std::placeholders::_2);
	sfmlHandlers[sfmlHandlersCount++] = handler;
}