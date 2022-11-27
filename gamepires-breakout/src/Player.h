#pragma once
#include <vector>

std::shared_ptr<Sprite> playerSprite;
std::shared_ptr<Object> player;

const float playerSpeed = 0.4f;

void initPlayer() {
	playerSprite.reset(new Sprite());
	playerSprite->loadMedia("src/assets/player.png");
	player.reset(new Object(playerSprite, Game::windowWidth / 2.f - playerSprite->getWidth() / 2.f, Game::windowHeight - 64.f));
}

void followMouseAndMoveSlowly(double delta) {
	if((int)round(player->getX() + player->getWidth() / 2) != Input::getMousePos().x) {
		float moveX = Input::getMousePos().x - player->getX() - player->getWidth() / 2;
		if(moveX > 0.f) {
			player->moveX(std::min(moveX, (float)(playerSpeed * delta)));
		} else if(moveX < 0.f) {
			player->moveX(std::max(moveX, (float)(-playerSpeed * delta)));
		}
	}
}

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

void renderPlayer(double delta) {
	followMouseAndMoveSlowly(delta);
	playerCheckCollision(delta);
	player->render();
}

void freePlayer() {
	player.reset();
	playerSprite.reset();
}