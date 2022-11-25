#include "Game.h"

Object *test = nullptr;

void main_program() {

}

void start() {
	test = new Object();
	test->loadMedia("src/assets/test.png");
	//LOG_INFO(Game::windowHeight);
}

void running(double delta) {
	if(test != nullptr) {
		test->move(0.1f * (float)delta, 0);
		test->render();

		if(test->getX() > 500.f) {
			delete test;
			test = nullptr;
		}
	}

}

void exit() {
	if (test != nullptr)
		delete test;
}

