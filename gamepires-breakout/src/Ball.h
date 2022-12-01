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

extern void checkBallBorderCollision();
extern void checkBallPlayerCollision();
extern void checkBallBrickCollision();

std::shared_ptr<Object> ball;
float ballSpeed = BALL_DEFAULT_SPEED;
Vector2f ballVec = Vector2f(0.f, 0.f);

bool isStarted = false;

void initBall() {
	srand((unsigned int)time(NULL));

	ball.reset(new Object(loadedTextures[BALL_TEXTURE_PATH]));
}

void checkBallCollision() {
	checkBallBorderCollision();
	checkBallPlayerCollision();
	checkBallBrickCollision();
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
	ballSpeed = BALL_DEFAULT_SPEED;
	ballVec = Vector2f(0.f, 0.f);
	isStarted = false;

	ball.reset();
}