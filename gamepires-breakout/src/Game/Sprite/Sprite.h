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
	void render(Renderer *renderer,
				int x = 0,
				int y = 0,
				int width = NULL,
				int height = NULL,
				SDL_Rect *clip = NULL,
				double angle = 0,
				SDL_Point *center = NULL,
				SDL_RendererFlip flip = SDL_FLIP_NONE);
	SDL_Texture *getSDLTexture() { return s_Texture; }
	int getWidth() const { return s_Width; }
	int getHeight() const { return s_Height; }
protected:
	SDL_Texture *s_Texture = NULL;
	int s_Width = 0;
	int s_Height = 0;
};

