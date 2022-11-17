#pragma once
#include "Game.h"

class Renderer {
public:
	Renderer (WindowManager &window);
	~Renderer ();
private:
	SDL_Renderer *s_Renderer;
};
