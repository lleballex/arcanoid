#pragma once

#include "../Rect/Rect.h"
#include "../ColorTransition/ColorTransition.h"
#include "../colors.h"

#include <functional>

class Button : public Rect {
private:
	bool isHovered = false;

	COLOR bg = COLOR::PURPLE;
	COLOR bgOnHover = COLOR::PURPLE_HOVER;

	ColorTransition *bgTransition = nullptr;	

	sf::Font font;
	sf::Text text;

	std::function<void()> onClick;

public:
	Button(float x, float y, float width, float height, sf::String text);
	Button(float width, float height, sf::String text);
	~Button();

	void handleEvent(sf::Event* event, sf::RenderWindow *window);
	void update(float dt);
	void draw(sf::RenderWindow* window);
	void onPositionChange();
	
	void setBg(COLOR bg, COLOR bgOnHover);
	void setOnClick(const std::function<void()>& func);
};