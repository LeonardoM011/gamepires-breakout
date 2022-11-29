#pragma once

extern std::shared_ptr<XMLParser> curLevel;

std::shared_ptr<Sprite> background;

void initBackground() {
	background.reset(new Sprite());
	background->loadMedia(curLevel->getBackgroundTexture());
}

void renderBackground() {
	background->render();
}

void freeBackground() {
	background.reset();
}