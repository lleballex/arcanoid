#include "VerticalLyout.h"

VerticalLayout::VerticalLayout(int objectsCount, float x, float y, float width, float height) : objectsCount(objectsCount), Object(x, y, width, height) {
	objects = new Object*[objectsCount];
}

VerticalLayout::VerticalLayout(int objectsCount, float width, float height) : VerticalLayout(objectsCount, 0, 0, width, height) {}

VerticalLayout::~VerticalLayout() {
	delete[] objects;
}

void VerticalLayout::addObject(Object* obj) {
	objects[++lastObjectIdx] = obj;

	contentHeight += obj->getHeight();
	if (lastObjectIdx > 0) {
		contentHeight += gap;
	}

	float curContentHeight = 0;
	for (int i = 0; i <= lastObjectIdx; i++) {
		objects[i]->setY((height - contentHeight) / 2.f + curContentHeight);
		curContentHeight += gap + objects[i]->getHeight();
	}

	obj->setX((width - obj->getWidth()) / 2.f);
}

void VerticalLayout::draw(sf::RenderWindow *window) {
	for (int i = 0; i <= lastObjectIdx; i++) {
		objects[i]->draw(window);
	}
}

void VerticalLayout::setGap(float gap_) {
	gap = gap_;
}