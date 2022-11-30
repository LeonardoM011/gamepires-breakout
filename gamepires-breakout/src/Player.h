#pragma once
#include <vector>

#define PLAYER_TEXTURE_PATH "src/assets/textures/player.png"

std::shared_ptr<Object> player;

const float playerSpeed = 0.4f;

void initPlayer() {
	player.reset(new Object(loadedTextures[PLAYER_TEXTURE_PATH], Game::windowWidth / 2.f - loadedTextures[PLAYER_TEXTURE_PATH]->getWidth() / 2.f, Game::windowHeight - 64.f));
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
}