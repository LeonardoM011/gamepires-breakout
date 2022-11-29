#include "Game.h"

#include "Background.h"
#include "Wall.h"
#include "Bricks.h"
#include "Player.h"
#include "Ball.h"

std::shared_ptr<XMLParser> curLevel;

void main_program() {
	curLevel.reset(new XMLParser("src/assets/level1.xml"));
	/*for(auto b : bricks) {
		LOG_INFO("id:" << b.id << "|texture:" << b.texture << "|hitPoints:"
				 << b.hitPoints << "|hitSound:" << b.hitSound << "|breakSound:"
				 << b.breakSound << "|breakScore:" << b.breakScore);
	}*/
}

void start() {
	initBackground();
	initWall();
	initPlayer();
	initBall();
	initBricks();
}

void running(double delta) {
	renderBackground();
	renderWall();
	renderPlayer(delta);
	renderBall(delta);
	renderBricks();
}

void exit() {
	freeBackground();
	freeBall();
	freeWall();
	freePlayer();
	freeBricks();

	curLevel.reset();
}

