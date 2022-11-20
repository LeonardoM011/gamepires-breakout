#pragma once
#include <SDL.h>
#include "Window/WindowManager.h"
#include "Assert.h"

// EXTERN FUNCTIONS - for use inside main.cpp
extern void start();
extern void running(double delta);

class GameManager {
public:
	GameManager ();
	~GameManager ();
	void start();
	void update();
private:
	void init();
	WindowManager *s_Window;

	Sprite *sprite;
	SDL_Event e;

	bool isRunning = true;
};
