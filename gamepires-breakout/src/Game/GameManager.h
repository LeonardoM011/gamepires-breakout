#pragma once
#include "Game.h"

class GameManager {
public:
	GameManager ();
	~GameManager ();
	int start();
private:
	int init();
};
