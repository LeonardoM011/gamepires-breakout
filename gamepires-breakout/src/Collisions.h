#pragma once

extern void restartLevel();
extern void startLevel();
extern std::shared_ptr<Text> scoreText;
extern std::shared_ptr<Text> livesText;

// PLAYER COLLISIONS
void playerCheckCollision(double delta) {
	int rightBorder = Game::windowWidth - 44;
	int leftBorder = 44;
	int leftX = (int)round(player->getX());
	int rightX = (int)round(player->getX() + player->getWidth());

	if(rightX > rightBorder) {
		player->moveX((float)(rightBorder - rightX));
	}
	if(leftX < leftBorder) {
		player->moveX((float)(leftBorder - leftX));
	}
}

// BALL COLLISIONS
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
		/*ball->moveY((float)(bottomBorder - bottom));
		ballVec.y = -ballVec.y;
		loadedSounds[BARRIER_HIT_SOUND]->playSound();*/
		if(--lives <= 0) {
			loadedSounds[LOSE_ALL_SOUND]->playSound();
			lives = MAX_PLAYER_LIVES;
			points = 0;
			restartLevel();
			startLevel();
		} else {
			loadedSounds[LOSE_LIFE_SOUND]->playSound();
			livesText->updateText("Lives: " + std::to_string(lives), SDL_Color(DEFAULT_FONT_COLOR));
			freeBall();
			initBall();
		}
	}
	if(top < topBorder) {
		ball->moveY((float)(topBorder - top));
		ballVec.y = -ballVec.y;
		loadedSounds[BARRIER_HIT_SOUND]->playSound();
	}
}

void checkBallBrickCollision() {
	if(bricks.empty()) {
		if(++level >= levels.size()) {
			// WIN
			level = 0;
			return;
		}
		lives = MAX_PLAYER_LIVES;
		points = 0;
		restartLevel();
		startLevel();
		return;
	}

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
			float diffSqrd = (float)sqrt(pow(diffX, 2) + pow(diffY, 2));
			if(abs(diffX) < abs(diffY)) {
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
				points += bricks[i]->getScore();
				scoreText->updateText("Score: " + std::to_string(points), SDL_Color(DEFAULT_FONT_COLOR));
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
		ballVec = normalize(Vector2f(-(-center.x + player->getX() + player->getWidth() / 2.f) / player->getWidth(), PLAYER_BALL_CURVE));
		loadedSounds[PLAYER_HIT_SOUND]->playSound();
	}

}
