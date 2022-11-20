#include "Sprite.h"
#include <cstring>

Sprite::Sprite() {
}

Sprite::~Sprite() {
	SDL_FreeSurface(s_MediaSurface);
}

void Sprite::loadMedia(std::string imagePath) {
	LOG_INFO("loading image " + imagePath);
	s_MediaSurface = SDL_LoadBMP(imagePath.c_str());
	ASSERT_THAT(s_MediaSurface != NULL, "image " + imagePath + " failed to load")
	LOG_OK("image " + imagePath + " successfully loaded");
}
