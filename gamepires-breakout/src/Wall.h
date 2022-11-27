#pragma once
#include <vector>

std::shared_ptr<Sprite> wallSprite;
std::vector<std::shared_ptr<Object>> wall;

SDL_Rect wallCol = SDL_Rect(Game::windowWidth - 44, 0, 32, Game::windowHeight);

void initWall() {
	wallSprite.reset(new Sprite());
	wallSprite->loadMedia("src/assets/brick_white.png");

	// TOP
	for(int i = 12; i < Game::windowWidth - 31; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(wallSprite, (float)i, 16.f, 32.f, 0.f));
		wall.push_back(block);
	}
	// LEFT
	for(int i = 32 + 16; i < Game::windowHeight; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(wallSprite, 12.f, (float)i, 32.f, 0.f));
		wall.push_back(block);
	}

	// RIGHT
	for(int i = 32 + 16; i < Game::windowHeight; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(wallSprite, Game::windowWidth - 12.f - 32.f, (float)i, 32.f, 0.f));
		wall.push_back(block);
	}
}

void renderWall() {
	for(int i = 0; i < wall.size(); i++) {
		wall[i]->render();
	}
}

void freeWall() {
	for(int i = 0; i < wall.size(); i++) {
		wall[i].reset();
	}
	wall.clear();
	wallSprite.reset();
}