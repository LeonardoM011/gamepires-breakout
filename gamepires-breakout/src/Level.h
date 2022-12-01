#pragma once

void startLevel() {
	curLevel = levels[level];
	initBackground();
	initWall();
	initPlayer();
	initBall();
	initBricks();
}

void renderLevel(double delta) {
	renderBackground();
	renderWall();
	renderPlayer(delta);
	renderBall(delta);
	renderBricks();
}

void restartLevel() {
	freeBackground();
	freeBall();
	freeWall();
	freePlayer();
	freeBricks();
}