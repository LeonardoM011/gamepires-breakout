#pragma once
#include <string>
#include <SDL.h>
#include "Assert.h"
#include "Renderer/Renderer.h"

class Sprite {
public:
	Sprite();
	~Sprite();
	void loadMedia(std::string imagePath);
	void render(int x = 0,
				int y = 0,
				int width = NULL,
				int height = NULL,
				SDL_Rect *clip = NULL,
				double angle = 0,
				SDL_Point *center = NULL,
				SDL_RendererFlip flip = SDL_FLIP_NONE);
	SDL_Texture *getSDLTexture() { return m_Texture; }
	static void bindRenderer(Renderer *renderer) { s_Renderer = renderer; }
	int getWidth() const { return m_Width; }
	int getHeight() const { return m_Height; }
protected:
	SDL_Texture *m_Texture = NULL;
	int m_Width = 0;
	int m_Height = 0;

	static Renderer *s_Renderer;
};

