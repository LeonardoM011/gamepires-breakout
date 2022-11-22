#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"

class WindowManager {
public:
	WindowManager (std::string title, int width, int height);
	~WindowManager ();
	void update();
	SDL_Window *getSDLWindow () { return s_Window; }
private:
	SDL_Window *s_Window = NULL;
};

