#include "Sprite.h"
#include <sdl2-image/SDL_image.h>
#include "Renderer/Renderer.h"

Sprite::Sprite() {
}

Sprite::~Sprite() {
	SDL_DestroyTexture(s_Texture);
}

void Sprite::loadMedia(Renderer *renderer, std::string imagePath) {
	LOG_INFO("loading image " + imagePath);
	SDL_Surface *mediaSurface = IMG_Load(imagePath.c_str());
	ASSERT_THAT(mediaSurface != NULL, "image " + imagePath + " failed to load");

	s_Texture = SDL_CreateTextureFromSurface(renderer->getSDLRenderer(), mediaSurface);
	ASSERT_THAT(s_Texture != NULL, "texture " + imagePath + "failed to create");
	s_Width = mediaSurface->w;
	s_Height = mediaSurface->h;
	SDL_FreeSurface(mediaSurface);
	LOG_OK("image " + imagePath + " successfully loaded");
}

void Sprite::render(Renderer *renderer) {
	SDL_RenderCopy(renderer->getSDLRenderer(), s_Texture, NULL, NULL);
}
