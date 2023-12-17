#define M_PI 3.14

#include "Ball.h"
#include "../Game/utils.h"

#include <cmath>

// TODO: fix coordinates, radius, speed
Ball::Ball() : Circle(10, 40, 10) {
	speedX = 0;
	speedY = speed;
	color = COLOR::WHITE;
	
	shape->setFillColor(sf::Color(color));

	eventManager.subscribe(EVENT::GAME_COLLIDE_BALL_BLOCK, nullptr, &Ball::onBlockCollide, this);
	eventManager.subscribe(EVENT::GAME_COLLIDE_BALL_PLATFORM, nullptr, &Ball::onPlatformCollide, this);
};

void Ball::update(float dt) {
	x += speedX * dt;
	y += speedY * dt;
	setPosition(x, y);
}

void Ball::draw(sf::RenderWindow *window) {
	window->draw(*shape);
}

void Ball::onBlockCollide(void* data_) {
	BallBlockCollideData *data = static_cast<BallBlockCollideData*>(data_);

	if (data->ball == this && data->block->isAlive()) {
		if (abs(data->collision[1]) > abs(data->collision[0])) {
			setY(y + data->collision[1]);
			speedY = -speedY;
		}
		else {
			setX(x + data->collision[0]);
			speedX = -speedX;
		}

		if (data->block->isSolid()) {
			setColor(data->block->getColor());
		}
	}
}

void Ball::onPlatformCollide(void* data_) {
	BallPlatformCollideData* data = static_cast<BallPlatformCollideData*>(data_);

	if ((float)rand() / RAND_MAX >= 0.3 || true) {
		float offsetX = (float)rand() / RAND_MAX * 500 - 250;
		float offsetY = (float)rand() / RAND_MAX * 500 - 250;
		float directionX = centerX - x + offsetX;
		float directionY = centerY - y + offsetY;
		float distance = sqrt(directionX * directionX + directionY * directionY);

		speedX = (directionX / distance) * speed;
		speedY = (directionY / distance) * speed;
	}

	//float newAngle = float(rand()) / RAND_MAX * M_PI * 2 - M_PI;

	//if (abs(data->collision[1]) > abs(data->collision[0])) {
	//	if (data->collision[1] > 0) {
	//		speedX = speed * cos(newAngle);
	//		speedY = speed * abs(sin(newAngle));
	//	}
	//	else {
	//		speedX = speed * cos(newAngle);
	//		speedY = -speed * abs(sin(newAngle));
	//	}

	//	setY(y + data->collision[1]);
	//}
	//else {
	//	if (data->collision[0] > 0) {
	//		speedX = speed * cos(newAngle);
	//		speedY = speed * sin(newAngle);
	//	}
	//	else {
	//		speedX = -speed * cos(newAngle);
	//		speedY = speed * sin(newAngle);
	//	}

	//	setX(x + data->collision[0]);
	//}
}

void Ball::setColor(COLOR newColor) {
	color = newColor;
	shape->setFillColor(sf::Color(color));
}

void Ball::setSpeedAngle(float angle) {
	speedX = speed * cos(angle);
	speedY = speed * sin(angle);
}

void Ball::setCenterPosition(float x, float y) {
	centerX = x;
	centerY = y;
}

COLOR Ball::getColor() {
	return color;
}

