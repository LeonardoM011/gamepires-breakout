#pragma once
#include <SDL.h>
#include "Window/WindowManager.h"
#include "Assert.h"

#define RENDERER_COLOR 0xFF, 0x00, 0xFF, 0xFF

class Renderer {
public:
	Renderer (WindowManager *window);
	~Renderer ();
	void prepare();
	void update();
	SDL_Renderer *getSDLRenderer() { return s_Renderer; }
private:
	SDL_Renderer *s_Renderer;
};
