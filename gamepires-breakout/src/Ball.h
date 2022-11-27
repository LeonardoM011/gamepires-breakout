#pragma once
#include <vector>
#include <random>

struct Vector2f {
	float x;
	float y;
};

Vector2f normalize(Vector2f vec) {
	float len = std::pow(vec.x, 2.f) + std::pow(vec.y, 2.f);
	len = sqrt(len);
	return Vector2f(vec.x / len, vec.y / len);
}

std::shared_ptr<Sprite> ballSprite;
std::shared_ptr<Object> ball;
float ballSpeed = 0.5f;
Vector2f ballVec = Vector2f(0.f, 0.f);

bool isStarted = false;

void initBall() {
	srand((unsigned int)time(NULL));

	wallSprite.reset(new Sprite());
	wallSprite->loadMedia("src/assets/ball_white.png");

	ball.reset(new Object(wallSprite));
}

void checkBallBorderCollision() {
	int rightBorder = Game::windowWidth - 44;
	int leftBorder = 44;
	int topBorder = 48;
	int bottomBorder = Game::windowHeight;

	int left = (int)round(ball->getX());
	int right = (int)round(ball->getX() + ball->getWidth());
	int top = (int)round(ball->getY());
	int bottom = (int)round(ball->getY() + ball->getHeight());

	if(right > rightBorder) {
		ball->moveX((float)(rightBorder - right));
		ballVec.x = -ballVec.x;
	}
	if(left < leftBorder) {
		ball->moveX((float)(leftBorder - left));
		ballVec.x = -ballVec.x;
	}
	if(bottom > bottomBorder) {
		ball->moveY((float)(bottomBorder - bottom));
		ballVec.y = -ballVec.y;
	}
	if(top < topBorder) {
		ball->moveY((float)(topBorder - top));
		ballVec.y = -ballVec.y;
	}
}

void checkBallPlayerCollision() {
	SDL_Point closestPoint;

	int left = (int)round(ball->getX());
	int right = (int)round(ball->getX() + ball->getWidth());
	int top = (int)round(ball->getY());
	int bottom = (int)round(ball->getY() + ball->getHeight());
	SDL_Point center = SDL_Point((int)round(ball->getX() + ball->getWidth() / 2.f),
								 (int)round(ball->getY() + ball->getHeight() / 2.f));

	int leftPlayer = (int)round(player->getX());
	int rightPlayer = (int)round(player->getX() + player->getWidth());
	int topPlayer = (int)round(player->getY());
	int bottomPlayer = (int)round(player->getY() + player->getHeight());

	//Find closest x offset
	if(bottom < topPlayer || top > bottomPlayer)
		return;

	if(center.x < leftPlayer) {
		closestPoint = SDL_Point(leftPlayer, topPlayer);
	} else if(center.x < rightPlayer) {
		closestPoint = SDL_Point(center.x, topPlayer);
	} else {
		closestPoint = SDL_Point(rightPlayer, topPlayer);
	}

	if(pow(ball->getHeight() / 2.f, 2) >= pow(closestPoint.x - center.x, 2) + pow(closestPoint.y - center.y, 2)) {
		ballVec = normalize(Vector2f(-(- center.x + player->getX() + player->getWidth() / 2.f) / player->getWidth(), -0.5f));
	}

}

void checkBallCollision() {
	checkBallBorderCollision();
	checkBallPlayerCollision();
}

void ballBeforeStarting() {
	ball->setX(player->getX() + player->getWidth() / 2 - ball->getWidth() / 2);
	ball->setY(player->getY() - ball->getWidth() - 1.f);
	if(Input::getMouseButton() == SDL_BUTTON_LEFT) {
		ballVec = normalize(Vector2f(((float)(std::rand() % 10) - 5.f), -15.f));
		isStarted = true;
	}
	ball->render();
}

void renderBall(double delta) {
	if(!isStarted) {
		ballBeforeStarting();
		return;
	}

	checkBallCollision();
	ball->moveX(ballVec.x * ballSpeed * (float)delta);
	ball->moveY(ballVec.y * ballSpeed * (float)delta);
	ball->render();
}

void freeBall() {
	ball.reset();
	ballSprite.reset();
}