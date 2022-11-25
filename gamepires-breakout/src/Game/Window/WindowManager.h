#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"

class WindowManager {
public:
	WindowManager (std::string title, int width, int height);
	~WindowManager ();
	void update();
	SDL_Window *getSDLWindow () { return m_Window; }
private:
	SDL_Window *m_Window = NULL;
};

