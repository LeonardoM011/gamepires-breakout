#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"
#include "Renderer/Renderer.h"

class Sprite {
public:
	Sprite();
	~Sprite();
	void loadMedia(Renderer *renderer, std::string imagePath);
	void render(Renderer *renderer);
	SDL_Texture *getSDLTexture() { return s_Texture; }
	int getWidth() const { return s_Width; }
	int getHeight() const { return s_Height; }
private:
	SDL_Texture *s_Texture = NULL;
	int s_Width = 0;
	int s_Height = 0;
};

