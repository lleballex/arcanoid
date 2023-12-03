#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, sf::String text_) : Rect(x, y, width, height) {
	bgTransition = new ColorTransition(sf::Color(bg));

	font.loadFromFile("./assets/mont-bold.ttf");
	text.setFont(font);	
	text.setString(text_);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color(COLOR::WHITE));
	const_cast<sf::Texture&>(font.getTexture(25)).setSmooth(false);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	eventManager.subscribe(EVENT::HOVER, this, this, std::bind(&Button::onHover, this));
	eventManager.subscribe(EVENT::UNHOVER, this, this, std::bind(&Button::onUnhover, this));
}

Button::Button(float width, float height, sf::String text) : Button(0, 0, width, height, text) {}

Button::~Button() {
	delete bgTransition;
}

void Button::update(float dt) {
	bgTransition->update(dt);
}

void Button::draw(sf::RenderWindow* window) {
	shape->setFillColor(bgTransition->getColor());

	window->draw(*shape);
	window->draw(text);
}

void Button::onPositionChange() {
	shape->setPosition(x, y);
	text.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
}

void Button::onSizeChange() {
	shape->setSize(sf::Vector2f(width, height));
	text.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
}

void Button::onHover() {
	bgTransition->start(sf::Color(bgOnHover));
}

void Button::onUnhover() {
	bgTransition->start(sf::Color(bg));
}

void Button::setBg(COLOR bg_, COLOR bgOnHover_) {
	bg = bg_;
	bgOnHover = bgOnHover_;
}