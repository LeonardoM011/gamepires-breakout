#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"

class Sprite {
public:
	Sprite();
	~Sprite();
	void loadMedia(std::string imagePath);
	SDL_Surface* getSDLSurface() { return s_MediaSurface; }
private:
	SDL_Surface *s_MediaSurface = NULL;
};

