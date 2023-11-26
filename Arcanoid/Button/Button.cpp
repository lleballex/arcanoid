#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::String text_) : Rect(x, y, width, height) {
	bgTransition = new ColorTransition(sf::Color(bg));

	font.loadFromFile("c:/users/lleballex/downloads/mont-bold.ttf");
	text.setFont(font);	
	text.setString(text_);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color(COLOR::WHITE));
	const_cast<sf::Texture&>(font.getTexture(25)).setSmooth(false);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
}

Button::Button(float width, float height, sf::String text) : Button(0, 0, width, height, text) {}

Button::~Button() {
	delete bgTransition;
}

void Button::handleEvent(sf::Event* event, sf::RenderWindow *window) {
	if (event->type == sf::Event::MouseButtonReleased) {
		const sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		if (contains(mousePos.x, mousePos.y) && onClick) {
			onClick();
		}
	}
}

void Button::update(float dt) {
	bgTransition->update(dt);
}

void Button::draw(sf::RenderWindow* window) {
	const sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	if (contains(mousePos.x, mousePos.y)) {
		if (!isHovered) {
			isHovered = true;
			bgTransition->start(sf::Color(bgOnHover));
		}
	}
	else {
		if (isHovered) {
			isHovered = false;
			bgTransition->start(sf::Color(bg));
		}
	}

	shape->setFillColor(bgTransition->getColor());

	window->draw(*shape);
	window->draw(text);
}

void Button::onPositionChange() {
	shape->setPosition(x, y);
	text.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
}

void Button::setBg(COLOR bg_, COLOR bgOnHover_) {
	bg = bg_;
	bgOnHover = bgOnHover_;
}

void Button::setOnClick(const std::function<void()>& func) {
	onClick = func;
}