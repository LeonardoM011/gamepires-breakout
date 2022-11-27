#include "Game.h"
#include "Wall.h"
#include "Player.h"

void main_program() {

}

void start() {
	initWall();
	initPlayer();
}

void running(double delta) {
	renderWall();
	renderPlayer(delta);
}

void exit() {
	freeWall();
	freePlayer();
}

