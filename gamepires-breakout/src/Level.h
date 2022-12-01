#pragma once

void startLevel() {
	curLevel = levels[level];
	initBackground();
	initWall();
	initPlayer();
	initBall();
	initBricks();
	initScoreboard();
}

void renderLevel(double delta) {
	renderBackground();
	renderWall();
	renderPlayer(delta);
	renderBall(delta);
	renderBricks();
	renderScoreboard();
}

void restartLevel() {
	freeBackground();
	freeBall();
	freeWall();
	freePlayer();
	freeBricks();
	freeScoreboard();
}