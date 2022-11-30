#pragma once
#include <vector>
#include <random>

#define BALL_TEXTURE_PATH "src/assets/textures/ball_white.png"
#define BARRIER_HIT_SOUND "src/assets/soundfx/sound_hit_barrier.wav"

struct Vector2f {
	float x;
	float y;
};

Vector2f normalize(Vector2f vec) {
	float len = std::pow(vec.x, 2.f) + std::pow(vec.y, 2.f);
	len = sqrt(len);
	return Vector2f(vec.x / len, vec.y / len);
}

std::shared_ptr<Object> ball;
float ballSpeed = 10.0f;
Vector2f ballVec = Vector2f(0.f, 0.f);

bool isStarted = false;

void initBall() {
	srand((unsigned int)time(NULL));

	ball.reset(new Object(loadedTextures[BALL_TEXTURE_PATH]));
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
		loadedSounds[BARRIER_HIT_SOUND]->playSound();
	}
	if(left < leftBorder) {
		ball->moveX((float)(leftBorder - left));
		ballVec.x = -ballVec.x;
		loadedSounds[BARRIER_HIT_SOUND]->playSound();
	}
	if(bottom > bottomBorder) {
		ball->moveY((float)(bottomBorder - bottom));
		ballVec.y = -ballVec.y;
		loadedSounds[BARRIER_HIT_SOUND]->playSound();
	}
	if(top < topBorder) {
		ball->moveY((float)(topBorder - top));
		ballVec.y = -ballVec.y;
		loadedSounds[BARRIER_HIT_SOUND]->playSound();
	}
}

void checkBallBrickCollision() {
	if(bricks.empty())
		return;

	float left = ball->getX();
	float right = ball->getX() + ball->getWidth();
	float top = ball->getY();
	float bottom = ball->getY() + ball->getHeight();
	float radius = ball->getWidth() / 2.f;
	Vector2f center = Vector2f(ball->getX() + ball->getWidth() / 2.f,
							   ball->getY() + ball->getHeight() / 2.f);

	int i = 0;
	for(auto brick : bricks) {
		Vector2f closestPoint;

		float leftBrick = brick->getX();
		float rightBrick = brick->getX() + brick->getWidth();
		float topBrick = brick->getY();
		float bottomBrick = brick->getY() + brick->getHeight();

		if(center.y < topBrick) {
			closestPoint.y = topBrick;
		} else if(center.y < bottomBrick) {
			closestPoint.y = center.y;
		} else {
			closestPoint.y = bottomBrick;
		}

		if(center.x < leftBrick) {
			closestPoint.x = leftBrick;
		} else if(center.x < rightBrick) {
			closestPoint.x = center.x;
		} else {
			closestPoint.x = rightBrick;
		}

		if(pow(ball->getHeight() / 2.f, 2) >= pow(closestPoint.x - center.x, 2) + pow(closestPoint.y - center.y, 2)) {
			bricks[i]->hit();

			float diffX = center.x - closestPoint.x;
			float diffY = center.y - closestPoint.y;
			float diffSqrd = sqrt(pow(diffX, 2) + pow(diffY, 2));
			if(abs(diffX) < abs(diffY) ) {
				if(diffY > 0) {
					ball->moveY(radius - abs(diffSqrd));
				} else {
					ball->moveY(-(radius - abs(diffSqrd)));
				}
				ballVec.y = -ballVec.y;
			} else {
				if(diffX > 0) {
					ball->moveX(radius - abs(diffSqrd));
				} else {
					ball->moveX(-(radius - abs(diffSqrd)));
				}
				ballVec.x = -ballVec.x;
			}


			if(bricks[i]->didBreak()) {
				bricks[i]->playBreakSound();
				bricks[i].reset();
				bricks.erase(bricks.begin() + i);
				break;
			}

			bricks[i]->playHitSound();


		}
		i++;
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
		ballVec = normalize(Vector2f(-(- center.x + player->getX() + player->getWidth() / 2.f) / player->getWidth(), -0.3f));
	}

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
	ball.reset();
}