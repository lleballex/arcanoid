#include "EventManager.h"
#include <iostream>

EventManager::EventManager() {
	handlers = new EventHandler[100];
	sfmlHandlers = new SFMLEventHandler[100];
}

EventManager::~EventManager() {
	delete[] handlers;
	delete[] sfmlHandlers;
}

EventManager& EventManager::getInstance() {
	static EventManager instance;
	return instance;
}

void EventManager::emit(EVENT event, void *sender) {
	for (int i = 0; i < handlersCount; i++) {
		if (handlers[i].event == event && (handlers[i].sender == sender || !handlers[i].sender)) {
			handlers[i].callback();
		}
	}
}

void EventManager::emitSFML(sf::Event *event, sf::RenderWindow *window) {
	for (int i = 0; i < sfmlHandlersCount; i++) {
		sfmlHandlers[i].callback(event, window);
	}
}

void EventManager::unsubscribe(void* reciever) {
	for (int i = 0; i < sfmlHandlersCount; i++) {
		if (sfmlHandlers[i].reciever == reciever) {
			for (int j = i + 1; j < sfmlHandlersCount; j++) {
				sfmlHandlers[j - 1] = sfmlHandlers[j];
			}
			sfmlHandlersCount--;
			i--;
		}
	}

	for (int i = 0; i < handlersCount; i++) {
		if (handlers[i].reciever == reciever) {
			for (int j = i + 1; j < handlersCount; j++) {
				handlers[j - 1] = handlers[j];
			}
			handlersCount--;
			i--;
		}
	}
}