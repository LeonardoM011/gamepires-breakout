#pragma once

std::shared_ptr<Sprite> background;

void initBackground() {
	background.reset(new Sprite(curLevel->getBackgroundTexture()));
}

void renderBackground() {
	background->render();
}

void freeBackground() {
	background.reset();
}