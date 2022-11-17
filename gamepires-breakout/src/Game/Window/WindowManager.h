#pragma once
#include "Game.h"

class WindowManager {
public:
	WindowManager (std::string title, int width, int height);
	~WindowManager ();
	SDL_Window *getSDLWindow () { return s_Window; }
private:
	SDL_Window *s_Window;
};

