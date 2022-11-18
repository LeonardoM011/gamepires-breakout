#pragma once
#include <SDL.h>
#include "Assert.h"

// EXTERN FUNCTIONS - for use inside main.cpp
extern void start();
extern void running(double delta);

class GameManager {
public:
	GameManager ();
	~GameManager ();
	void start();
private:
	void init();
};
