#include "Sprite.h"
#include <sdl2-image/SDL_image.h>
#include "Renderer/Renderer.h"

std::shared_ptr<Renderer> Sprite::s_Renderer = nullptr;

Sprite::Sprite(std::string imagePath) {
	LOG_INFO("loading image " + imagePath);
	SDL_Surface *mediaSurface = IMG_Load(imagePath.c_str());
	ASSERT_THAT(mediaSurface != NULL, "image " + imagePath + " failed to load");

	m_Texture = SDL_CreateTextureFromSurface(s_Renderer->getSDLRenderer(), mediaSurface);
	ASSERT_THAT(m_Texture != NULL, "texture " + imagePath + "failed to create");
	m_Width = mediaSurface->w;
	m_Height = mediaSurface->h;
	SDL_FreeSurface(mediaSurface);
	LOG_OK("image " + imagePath + " successfully loaded");
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_Texture);
	m_Texture = NULL;
}

void Sprite::render(int x,
					int y,
					int width,
					int height,
					SDL_Rect *clip,
					double angle,
					SDL_Point *center,
					SDL_RendererFlip flip) {

	if(!width) width = m_Width;
	if(!height) height = m_Height;

	SDL_Rect rect = {x, y, width, height};
	SDL_RenderCopyEx(s_Renderer->getSDLRenderer(),
					 m_Texture,
					 clip,
					 &rect,
					 angle,
					 center,
					 flip);
}
