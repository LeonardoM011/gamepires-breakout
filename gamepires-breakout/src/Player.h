#pragma once
#include <vector>

extern void playerCheckCollision(double delta);

std::shared_ptr<Object> player;

float playerSpeed = DEFAULT_PLAYER_SPEED;

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

void renderPlayer(double delta) {
	followMouseAndMoveSlowly(delta);
	playerCheckCollision(delta);
	player->render();
}

void freePlayer() {
	playerSpeed = DEFAULT_PLAYER_SPEED;
	player.reset();
}