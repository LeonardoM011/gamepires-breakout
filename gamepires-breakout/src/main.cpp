#include "Game.h"

Object *test = nullptr;

void main_program () {

}

void start () {
	test = new Object();
	test->loadMedia("src/assets/test.png");
}

void running (double delta) {
	//LOG_INFO(delta);
	test->move(0.1f * (float)delta, 0);
	test->render();
}

