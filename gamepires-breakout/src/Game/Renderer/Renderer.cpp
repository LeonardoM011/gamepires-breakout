#include "Renderer.h"
#include <sdl2-image/SDL_image.h>

Renderer::Renderer (WindowManager *window) {
	s_Renderer = SDL_CreateRenderer (window->getSDLWindow (), -1, SDL_RENDERER_ACCELERATED);
	ASSERT_THAT (s_Renderer != NULL, "SDL Renderer failed to create");

	SDL_SetRenderDrawColor(s_Renderer, RENDERER_COLOR);
}

Renderer::~Renderer () {
	SDL_DestroyRenderer(s_Renderer);
}

void Renderer::prepare() {
	SDL_SetRenderDrawColor(s_Renderer, RENDERER_COLOR);
	SDL_RenderClear(s_Renderer);
}

void Renderer::update() {
	SDL_RenderPresent(s_Renderer);
}
