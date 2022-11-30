#pragma once
#include <vector>

#define WALL_TEXTURE_PATH "src/assets/textures/brick_white.png"

std::vector<std::shared_ptr<Object>> wall;

void initWall() {

	// TOP
	for(int i = 12; i < Game::windowWidth - 31; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(loadedTextures[WALL_TEXTURE_PATH], (float)i, 16.f, 32.f, 0.f));
		wall.push_back(block);
	}
	// LEFT
	for(int i = 32 + 16; i < Game::windowHeight; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(loadedTextures[WALL_TEXTURE_PATH], 12.f, (float)i, 32.f, 0.f));
		wall.push_back(block);
	}

	// RIGHT
	for(int i = 32 + 16; i < Game::windowHeight; i += 32) {
		std::shared_ptr<Object> block;
		block.reset(new Object(loadedTextures[WALL_TEXTURE_PATH], Game::windowWidth - 12.f - 32.f, (float)i, 32.f, 0.f));
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
}