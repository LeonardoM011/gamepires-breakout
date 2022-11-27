#include "Game.h"
#include "Wall.h"
#include "Player.h"
#include "Ball.h"

void main_program() {

}

void start() {
	initWall();
	initPlayer();
	initBall();
}

void running(double delta) {
	renderWall();
	renderPlayer(delta);
	renderBall(delta);
}

void exit() {
	freeBall();
	freeWall();
	freePlayer();
}

