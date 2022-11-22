#include "Renderer.h"
#include <sdl2-image/SDL_image.h>

Renderer::Renderer (WindowManager *window) {
	s_Renderer = SDL_CreateRenderer (window->getSDLWindow (), -1, SDL_RENDERER_ACCELERATED);
	ASSERT_THAT (s_Renderer != NULL, "SDL Renderer failed to create");

	SDL_SetRenderDrawColor(s_Renderer, 0xFF, 0xFF, 0x00, 0xFF);
}

Renderer::~Renderer () {
	SDL_DestroyRenderer(s_Renderer);
}

void Renderer::prepare() {
	SDL_RenderClear(s_Renderer);
}

void Renderer::update() {
	SDL_RenderPresent(s_Renderer);
}
