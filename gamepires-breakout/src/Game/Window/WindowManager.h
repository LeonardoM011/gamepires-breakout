#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"
#include "Sprite/Sprite.h"

class WindowManager {
public:
	WindowManager (std::string title, int width, int height);
	~WindowManager ();
	void update();
	void applySprite(Sprite *sprite);
	SDL_Window *getSDLWindow () { return s_Window; }
	SDL_Surface *getSDLWindowSurface() { return s_Surface; }
private:
	SDL_Window *s_Window = NULL;
	SDL_Surface *s_Surface = NULL;
};

