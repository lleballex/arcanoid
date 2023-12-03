#include "Game.h"
#include "../SolidBlock/SolidBlock.h"
#include "../MultiBlock/MultiBlock.h"
#include "../VerticalPlatform/VerticalPlatform.h"
#include "../HorizontalPlatform/HorizontalPlatform.h"

Game::Game() {
	/*blocksCount = 7;
	blocks = new Block*[blocksCount];

	for (int i = 0; i < blocksCount - 2; i++) {
		blocks[i] = new Block(100 + i * 50, 100 + i * 50);
	}

	blocks[blocksCount - 1] = new SolidBlock(300, 50, COLOR::RED);
	blocks[blocksCount - 2] = new SolidBlock(10, 300, COLOR::WHITE);*/


	platforms = new Platform*[4];

	platforms[0] = new HorizontalPlatform;
	platforms[0]->setPosition((SCREEN_WIDTH - platforms[0]->getWidth()) / 2, 0);
	platforms[1] = new HorizontalPlatform;
	platforms[1]->setPosition((SCREEN_WIDTH - platforms[1]->getWidth()) / 2, SCREEN_HEIGHT - platforms[1]->getHeight());
	platforms[2] = new VerticalPlatform;
	platforms[2]->setPosition(0, (SCREEN_HEIGHT - platforms[2]->getHeight()) / 2);
	platforms[3] = new VerticalPlatform;
	platforms[3]->setPosition(SCREEN_WIDTH - platforms[3]->getWidth(), (SCREEN_HEIGHT - platforms[3]->getHeight()) / 2);

	for (int i = 0; i < 4; i++) {
		eventManager.subscribe(EVENT::CLICK, platforms[i], this, std::bind(&Game::setActivePlatformIdx, this, i));
		eventManager.subscribe(EVENT::MOVE, platforms[i], this, std::bind(&Game::setInitBallPosition, this));
		eventManager.subscribe(EVENT::RESIZE, platforms[i], this, std::bind(&Game::setInitBallPosition, this));
	}

	ball = new Ball;

	// level loading

	const int cellsCount = 10;
	int cells[cellsCount][cellsCount] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 3, 3, 0, 0, 0, 0},
		{0, 0, 0, 2, 1, 1, 2, 0, 0, 0},
		{0, 0, 3, 1, 3, 3, 1, 3, 0, 0},
		{0, 0, 3, 1, 3, 3, 1, 3, 0, 0},
		{0, 0, 0, 2, 1, 1, 2, 0, 0, 0},
		{0, 0, 0, 0, 3, 3, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	COLOR cellColors[cellsCount][cellsCount] = {
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::PINK,  COLOR::PINK,  COLOR::PINK,  COLOR::PINK,  COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::PINK,  COLOR::WHITE, COLOR::WHITE, COLOR::PINK,  COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::BLUE,  COLOR::WHITE, COLOR::WHITE, COLOR::BLUE , COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::BLUE , COLOR::BLUE , COLOR::BLUE , COLOR::BLUE , COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
		{COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE, COLOR::WHITE},
	};

	for (int i = 0; i < cellsCount; i++) {
		for (int j = 0; j < cellsCount; j++) {
			if (cells[i][j] > 0) {
				blocksCount++;
			}
		}
	}

	blocks = new Block * [blocksCount];

	int lastBlockIdx = -1;

	for (int i = 0; i < cellsCount; i++) {
		for (int j = 0; j < cellsCount; j++) {
			if (cells[i][j] == 1) {
				blocks[++lastBlockIdx] = new Block(j * 80 + ((SCREEN_WIDTH - 10 * 80) / 2), i * 50 + ((SCREEN_HEIGHT - 10 * 50) / 2), cellColors[i][j]);
			}
			else if (cells[i][j] == 2) {
				blocks[++lastBlockIdx] = new SolidBlock(j * 80 + ((SCREEN_WIDTH - 10 * 80) / 2), i * 50 + ((SCREEN_HEIGHT - 10 * 50) / 2), cellColors[i][j]);
			}
			else if (cells[i][j] == 3) {
				blocks[++lastBlockIdx] = new MultiBlock(j * 80 + ((SCREEN_WIDTH - 10 * 80) / 2), i * 50 + ((SCREEN_HEIGHT - 10 * 50) / 2));
			}
		}
	}
	
	heartTexture = new sf::Texture;
	heartTexture->loadFromFile("./assets/heart.png");
	heart = new sf::Sprite(*heartTexture);
	heart->setScale(25 / 48.f, 25 / 48.f);

	setInitBallPosition();

	eventManager.subscribeSFML(this, std::bind(&Game::handleSFMLEvent, this, std::placeholders::_1, std::placeholders::_2));
}

Game::~Game() {
	for (int i = 0; i < blocksCount; i++) {
		delete[] blocks[i];
	}
	delete[] blocks;

	for (int i = 0; i < 4; i++) {
		delete[] platforms[i];
	}
	delete[] platforms;
	
	delete ball;

	delete heart;
	delete heartTexture;
}

void Game::setInitBallPosition() {
	if (isStarted) return;

	switch (activePlatformIdx) {
	case 0:
		ball->setSpeedAngle(3.14 / 2);
		ball->setPosition(platforms[0]->getX() + platforms[0]->getWidth() / 2 - ball->getWidth() / 2,
						  platforms[0]->getY() + platforms[0]->getHeight() + 15);
		break;
	case 1:
		ball->setSpeedAngle(-3.14 / 2);
		ball->setPosition(platforms[1]->getX() + platforms[1]->getWidth() / 2 - ball->getWidth() / 2,
						  platforms[1]->getY() - ball->getHeight() - 15);
		break;
	case 2:
		ball->setSpeedAngle(0);
		ball->setPosition(platforms[2]->getX() + platforms[2]->getWidth() + 15,
						  platforms[2]->getY() + platforms[2]->getHeight() / 2 - ball->getHeight() / 2);
		break;
	case 3:
		ball->setSpeedAngle(3.14);
		ball->setPosition(platforms[3]->getX() - ball->getWidth() - 15,
						  platforms[3]->getY() + platforms[3]->getHeight() / 2 - ball->getHeight() / 2);
		break;
	}
	
}

void Game::setActivePlatformIdx(int idx) {
	activePlatformIdx = idx;
	setInitBallPosition();
}

void Game::handleSFMLEvent(sf::Event* event, sf::RenderWindow* window) {
	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == sf::Keyboard::Space && !isStarted) {
			isStarted = true;
		}
		else if (event->key.code == sf::Keyboard::Escape) {
			eventManager.emit(EVENT::GO_HOME, this);
		}
	}
}

void Game::update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		for (int i = 0; i < 4; i++) {
			platforms[i]->moveLeft(dt, platforms[i]->getHeight());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		for (int i = 0; i < 4; i++) {
			platforms[i]->moveRight(dt, SCREEN_WIDTH - platforms[i]->getHeight());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		for (int i = 0; i < 4; i++) {
			platforms[i]->moveUp(dt, platforms[i]->getWidth());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		for (int i = 0; i < 4; i++) {
			platforms[i]->moveDown(dt, SCREEN_HEIGHT - platforms[i]->getWidth());
		}
	}

	if (isStarted) {
		ball->update(dt);

		for (int i = 0; i < 4; i++) {
			ball->handlePlatformCollide(platforms[i]->getX(), platforms[i]->getY(), platforms[i]->getWidth(), platforms[i]->getHeight());
		}

		for (int i = 0; i < blocksCount; i++) {
			if (blocks[i]->isAlive()) {
				if (ball->handleBlockCollide(blocks[i]->getX(), blocks[i]->getY(), blocks[i]->getWidth(), blocks[i]->getHeight())) {
					blocks[i]->onBallCollide(ball->getColor());
					if (blocks[i]->isSolid()) {
						ball->setColor(blocks[i]->getColor());
					}
				}
			}
		}

		if (!ball->isInsideWeakly(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)) {
			if (--health <= 0) {
				// TODO: add kinda plug
				eventManager.emit(EVENT::GO_HOME, this);
				return;
			}
			else {
				isStarted = false;
				setInitBallPosition();
			}
		}

		//bool isEnd = true;
		//for (int i = 0; i < blocksCount && isEnd; i++) {
		//	if (!blocks[i]->isAlive() || blocks[i]->isSolid()) {
		//		isEnd = false;
		//		
		//	}
		//}
		//if (isEnd) {
		//	// TODO: add kinda plug
		//	eventManager.emit(EVENT::GO_HOME, this);
		//	return;
		//}
	}
}

void Game::draw(sf::RenderWindow *window) {
	for (int i = 0; i < blocksCount; i++) {
		blocks[i]->draw(window);
	}

	for (int i = 0; i < 4; i++) {
		platforms[i]->draw(window);
	}

	ball->draw(window);

	for (int i = 0; i < health; i++) {
		heart->setPosition(i * 30, -3);
		window->draw(*heart);
	}
}