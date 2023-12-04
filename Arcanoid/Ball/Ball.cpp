#define M_PI 3.14

#include "Ball.h"

#include <cmath>

// TODO: fix coordinates, radius, speed
Ball::Ball() : Circle(10, 40, 10) {
	speedX = 0;
	speedY = speed;
	color = COLOR::WHITE;
	
	shape->setFillColor(sf::Color(color));
};

void Ball::update(float dt) {
	x += speedX * dt;
	y += speedY * dt;
	setPosition(x, y);
}

void Ball::draw(sf::RenderWindow *window) {
	window->draw(*shape);
}

bool Ball::handlePlatformCollide(float plX, float plY, float plWidth, float plHeight) {
	float *res = getRectCollision(plX, plY, plWidth, plHeight);

	if (!res) {
		return false;
	}

	if ((float)rand() / RAND_MAX >= 0.3) {
		float offsetX = (float)rand() / RAND_MAX * 400 - 200;
		float offsetY = (float)rand() / RAND_MAX * 400 - 200;
		float directionX = centerX - x + offsetX;
		float directionY = centerY - y + offsetY;
		float distance = sqrt(directionX * directionX + directionY * directionY);

		speedX = (directionX / distance) * speed;
		speedY = (directionY / distance) * speed;

		return true;
	}

	float newAngle = float(rand()) / RAND_MAX * M_PI * 2 - M_PI;

	if (abs(res[1]) > abs(res[0])) {
		if (res[1] > 0) {
			speedX = speed * cos(newAngle);
			speedY = speed * abs(sin(newAngle));
		}
		else {
			speedX = speed * cos(newAngle);
			speedY = -speed * abs(sin(newAngle));
		}

		setY(y + res[1]);

		delete[] res;
		return true;
	}
	else {
		if (res[0] > 0) {
			speedX = speed * cos(newAngle);
			speedY = speed * sin(newAngle);
		}
		else {
			speedX = -speed * cos(newAngle);
			speedY = speed * sin(newAngle);
		}

		setX(x + res[0]);

		delete[] res;
		return true;
	}
}


bool Ball::handleBlockCollide(float blockX, float blockY, float blockWidth, float blockHeight) {
	float *res = getRectCollision(blockX, blockY, blockWidth, blockHeight);

	if (!res) {
		return false;
	}
	
	if (abs(res[1]) > abs(res[0])) {
		setY(y + res[1]);
		speedY = -speedY;

		delete[] res;
		return true;
	}
	else {
		setX(x + res[0]);
		speedX = -speedX;

		delete[] res;
		return true;
	}
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

