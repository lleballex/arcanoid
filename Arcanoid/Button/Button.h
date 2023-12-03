#pragma once

#include "../Rect/Rect.h"
#include "../ColorTransition/ColorTransition.h"
#include "../config.h"

class Button : public Rect {
private:
	COLOR bg = COLOR::PURPLE;
	COLOR bgOnHover = COLOR::PURPLE_2;

	ColorTransition *bgTransition = nullptr;	

	sf::Font font;
	sf::Text text;

	void onRectChange();
	void onHover();
	void onUnhover();

public:
	Button(float x, float y, float width, float height, sf::String text);
	Button(float width, float height, sf::String text);
	~Button();

	void update(float dt);
	void draw(sf::RenderWindow* window);
	
	void setBg(COLOR bg, COLOR bgOnHover);
};