#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"

class WindowManager {
public:
	WindowManager (std::string title, int width, int height);
	~WindowManager ();
	void update();
	int getWidth() const { return m_Width; }
	int getHeight() const { return m_Height; }
	SDL_Window *getSDLWindow () { return m_Window; }
private:
	int m_Width;
	int m_Height;
	SDL_Window *m_Window = NULL;
};

